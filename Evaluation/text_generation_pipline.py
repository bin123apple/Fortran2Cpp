import torch
from transformers import pipeline
from datasets import load_dataset
from transformers import AutoTokenizer ,AutoModelForCausalLM

# Select the model that you want to test

# checkpoint = "bigcode/starcoder"
# checkpoint = "ise-uiuc/Magicoder-S-DS-6.7B"
# checkpoint = "WizardLM/WizardCoder-15B-V1.0"
# checkpoint = "codellama/CodeLlama-13b-Instruct-hf"
# checkpoint = "deepseek-ai/deepseek-coder-33b-instruct"
checkpoint = "Bin12345/F2C-Translator"


access_token = "" # Use your own huggingface token

# Muti GPU inference
model = AutoModelForCausalLM.from_pretrained(checkpoint,
                                             use_auth_token=access_token,
                                             device_map="auto") 

tokenizer = AutoTokenizer.from_pretrained(checkpoint, 
                                          use_auth_token=access_token,
                                          legacy=False)

# torch.float16
pipe = pipeline("text-generation", 
                model=model, 
                tokenizer=tokenizer,
                torch_dtype=torch.float16,)

input_dataset = load_dataset("Bin12345/HPC_Fortran_CPP")

translated_texts = []
index = 0
for split in input_dataset.keys():
    for fortran_code in input_dataset[split]['fortran']:     
        try:
            input_prompt = "Translate this Fortran code to C++: \n" + fortran_code
            print(F"input_prompt: \n{input_prompt}")
            if len(input_prompt) < 4000:
                new_chars = pipe(input_prompt, 
                            do_sample=True,
                            temperature=0.2,
                            max_new_tokens=512,)[0]["generated_text"][len(input_prompt):]
                print(f"#{index} Fortran Code has been translated. \nTranslated C++ Code:\n{new_chars}")
                index += 1
                string_literal_code = new_chars.replace('\n', '\\n').replace('\r', '\\r')
                translated_texts.append(string_literal_code)
        except Exception as e:
            print(f"An error occurred: {e}") 
            
# Write the processed C++ codes to a file
with open("log.txt", "w") as f: # Select the path where you want to store your results. 
    for text in translated_texts:
        f.write(text + '\n')
        
