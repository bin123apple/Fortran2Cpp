from openai import OpenAI
import tiktoken
import backoff 
from transformers import pipeline
from transformers import OPTForCausalLM, AutoTokenizer,GPT2LMHeadModel,AutoModelForCausalLM, AutoConfig,CodeLlamaTokenizer,AddedToken 

# @backoff.on_exception(backoff.expo, openai.error.OpenAIError, max_tries=2)
# def completions_with_backoff(**kwargs):
#     """
#     openai.ChatCompletion with backoff.
#     """
#     try:
#         return openai.ChatCompletion.create(**kwargs)
#     except openai.error.OpenAIError as e:
#         print(f"Error details: {e}")
#         raise


def generate_from_GPT(key,prompts, max_tokens, model="gpt-4", temperature=0.7, n=1):
    """
    Generate answer from GPT model with the given prompt.
    input:
        @max_tokens: the maximum number of tokens to generate; in this project, it is 8000 - len(fortran_code)
        @n: the number of samples to return
    return: a list of #n generated_ans when no error occurs, otherwise None

    return example (n=3):
        [
        {
        "index": 0,
        "message": {
            "role": "assistant",
            "content": "The meaning of life is subjective and can vary greatly"
        },
        "finish_reason": "length"
        },
        {
        "index": 1,
        "message": {
            "role": "assistant",
            "content": "As an AI, I don't have personal beliefs"
        },
        "finish_reason": "length"
        },
        {
        "index": 2,
        "message": {
            "role": "assistant",
            "content": "The meaning of life is subjective and can vary greatly"
        },
        "finish_reason": "length"
        }
    ]
    """
    
    client = OpenAI(base_url="https://openkey.cloud/v1", api_key=key)
    completion = client.chat.completions.create(
    model="gpt-4o",
    messages=prompts
    )
    try:
        # result = completions_with_backoff(
        #     model = model, 
        #     messages = prompts, 
        #     temperature = temperature, 
        #     max_tokens = max_tokens, 
        #     n = n
        # )
        client = OpenAI(base_url="https://openkey.cloud/v1", api_key=key)
        completion = client.chat.completions.create(
        model="gpt-4o",
        messages=prompts
        )

        generated_ans = completion.choices
        return generated_ans
    
    except Exception as e:
        print(f"An error occurred: {e}")
        return None

def load_local_model(model_name_or_path, device_num=3):
    """
    Load the model from the given model_name_or_path.
    """
    access_token = "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" # TODO

    dump_device = f'cuda:{device_num}'   # will only be used for single GPU inference
    # model_config = AutoConfig.from_pretrained(model_name_or_path)        
    # model_class = AutoModelForCausalLM.from_config(model_config)
    # model = model_class.from_pretrained(model_name_or_path,
    #                                     from_tf=bool(".ckpt" in model_name_or_path),
    #                                     config=model_config).to(dump_device)
    model = AutoModelForCausalLM.from_pretrained(model_name_or_path,
                                                 use_auth_token=access_token,
                                                 device_map="auto")
    # tokenizer = CodeLlamaTokenizer.from_pretrained(model_name_or_path, use_auth_token=access_token,fast_tokenizer=False)
    # tokenizer = AutoTokenizer.from_pretrained(model_name_or_path, eos_token = AddedToken("</s>", normalized = False, special=True))
    tokenizer = AutoTokenizer.from_pretrained("NousResearch/Llama-2-7b-chat-hf", 
                                                                                eos_token = AddedToken("</s>", 
                                                                                normalized = False, 
                                                                                special=True))
    # new_eos_token = "<|endoftext|>"
    # new_eos_token = "<|endoftext|>"
    # tokenizer.eos_token = new_eos_token
    text_generator = pipeline(
            model=model, 
            tokenizer=tokenizer, 
            task="text-generation"
        )
    return tokenizer, model, text_generator

## On Single GPU
# def generate_from_local_model(input_prompt, max_tokens, tokenizer, model, device_num, n=1, max_prompt_length=4096):
#     """
#     Generate answer from local model with the given prompt.
#     Input:
#         @device_num: the number of GPU to use, example: 3
#         @input_prompt: the prompt to be fed into the model: string
#         @n: the number of samples to return
#     Output:
#         @generated_ans: a list of #n generated_ans.

#     Example of usage for dataset processing:
#     tokenizer, model = load_local_model(model_name_or_path, device_num)
#     for i in range(len(dataset['fortran'])):
#         input_prompt = "Translate the following Fortran code to cpp " + dataset['fortran'][i]        
#         generated_ans = generate_from_local_model(input_prompt, max_tokens, tokenizer, model, device_num, max_prompt_length=1024)
#     """
#     dump_device = f'cuda:{device_num}'
#     input_ids = tokenizer.encode(input_prompt, return_tensors="pt").to(dump_device)
#     if len(input_prompt) < max_prompt_length:
#         if tokenizer.pad_token is None:
#             tokenizer.pad_token = tokenizer.eos_token
#         attention_mask = input_ids.ne(tokenizer.pad_token_id).float().to(dump_device)
#         outputs = model.generate(input_ids, max_length=max_tokens,num_return_sequences=n,eos_token_id=tokenizer.eos_token_id)
#         generated_ans = []
#         for i in range(n):
#             # print("outputs[i]",outputs[i])
#             predicted_answer = tokenizer.decode(outputs[i])
#             # print("predicted_answer afer tokenizer",predicted_answer)
#             generated_ans.append(predicted_answer[len(input_prompt)+4:]) # +4 is becuase there is a '<s> ' ahead
#     else:
#         print("This task is out of my max prompt length limitation!")


# On mutiple GPUs
def generate_from_local_model(input_prompt, max_tokens, tokenizer, text_generator, device_num, n=1, max_prompt_length=4096):
    """
    Generate answer from local model with the given prompt.
    Input:
        @device_num: the number of GPU to use, example: 3
        @input_prompt: the prompt to be fed into the model: string
        @n: the number of samples to return
    Output:
        @generated_ans: a list of #n generated_ans.

    Example of usage for dataset processing:
    tokenizer, model = load_local_model(model_name_or_path, device_num)
    for i in range(len(dataset['fortran'])):
        input_prompt = "Translate the following Fortran code to cpp " + dataset['fortran'][i]        
        generated_ans = generate_from_local_model(input_prompt, max_tokens, tokenizer, model, device_num, max_prompt_length=1024)
    """
    if len(input_prompt) < max_prompt_length:
        if tokenizer.pad_token is None:
            tokenizer.pad_token = tokenizer.eos_token
        outputs = text_generator(
                    input_prompt,
                    do_sample=True,
                    top_k=1,
                    num_return_sequences=1,
                    eos_token_id=tokenizer.eos_token_id,
                    max_length=max_tokens,
                )
        # print("output",outputs)
        generated_ans = []
        for i in range(n):
            # print("outputs[i]",outputs[i])
            # predicted_answer = tokenizer.decode(outputs[i])
            # print("predicted_answer afer tokenizer",predicted_answer)
            generated_ans.append(outputs[0]["generated_text"][len(input_prompt):]) # +4 is becuase there is a '<s> ' ahead
    else:
        print(f"The input length is {len(input_prompt)}. This task is out of my max prompt length limitation!")
    
    return generated_ans




 