import os
import torch
from transformers import pipeline, AutoTokenizer, AutoModelForCausalLM
from datasets import load_dataset
import time

# Parameters
CHECKPOINT = "Bin12345/Fortran2Cpp"
LOG_FILE = "translation_log.txt"
# set based on the selected model's capability
#MAX_INPUT_LENGTH = 4000
#MAX_NEW_TOKENS = 512
TEMPERATURE = 0.2
DATASET_NAME = "Bin12345/HPC_Fortran_CPP"

# Environment variable check
access_token = os.getenv('HUGGINGFACE_TOKEN')
if not access_token:
    raise ValueError("HUGGINGFACE_TOKEN environment variable is not set")

# Model and tokenizer setup
model = AutoModelForCausalLM.from_pretrained(CHECKPOINT,
                                             use_auth_token=access_token,
                                             device_map="auto")

tokenizer = AutoTokenizer.from_pretrained(CHECKPOINT,
                                          use_auth_token=access_token,
                                          legacy=False)
def log_progress(message):
    """Append a message to the log file with timestamp."""
    timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
    with open(LOG_FILE, "a") as f:
        f.write(f"[{timestamp}] {message}\n")


# Determine model's maximum input length and output tokens
MAX_INPUT_LENGTH = tokenizer.model_max_length

# output length should be similar to input length
MAX_NEW_TOKENS = min(
    model.config.max_position_embeddings - MAX_INPUT_LENGTH,
    int(MAX_INPUT_LENGTH * 1.2)
)

log_progress(f"Model's max input length: {MAX_INPUT_LENGTH}")
log_progress(f"Model's max new tokens: {MAX_NEW_TOKENS}")

pipe = pipeline("text-generation",
                model=model,
                tokenizer=tokenizer,
                torch_dtype=torch.float16)

# Load dataset
input_dataset = load_dataset(DATASET_NAME)

# Count total number of Fortran codes
total_codes = sum(len(input_dataset[split]['fortran']) for split in input_dataset.keys())

log_progress(f"Starting translation of {total_codes} Fortran codes.")

translated_count = 0
for split in input_dataset.keys():
    for fortran_code in input_dataset[split]['fortran']:
        translated_count += 1
        try:
            input_prompt = f"Translate this Fortran code to C++:\n{fortran_code}"
            log_progress(f"Processing code {translated_count}/{total_codes}")
            
            if len(input_prompt) < MAX_INPUT_LENGTH:
                new_chars = pipe(input_prompt,
                                 do_sample=True,
                                 temperature=TEMPERATURE,
                                 max_new_tokens=MAX_NEW_TOKENS)[0]["generated_text"][len(input_prompt):]
                
                log_progress(f"Code {translated_count}/{total_codes} translated successfully.")
                log_progress(f"Translated C++ Code:\n{new_chars}\n")
            else:
                log_progress(f"Code {translated_count}/{total_codes} skipped due to length exceeding {MAX_INPUT_LENGTH} characters.")
        except Exception as e:
            log_progress(f"Error translating code {translated_count}/{total_codes}: {str(e)}")

log_progress(f"Translation completed. {translated_count} out of {total_codes} codes processed.")
