import os
import json
from transformers import AutoTokenizer

tokenizer = AutoTokenizer.from_pretrained('Bin12345/AutoCoder')

original_data_json = "" # Input original json file
with open(original_data_json, 'r', encoding='utf-8') as file:
    data = json.load(file)

processed_data = []
count = 0
for item in data:
    message = ""
    for role in item["messages"]:
        message += role["content"]
    token_lenght = len(tokenizer.encode(message, add_special_tokens=True))
    if token_lenght > 10240:
        count += 1
    else:  
        processed_data.append(item)

for index, item in enumerate(processed_data):
    item['id'] = index + 1

directory = "" # Output folder
output_file_path = os.path.join(directory, '') # Output Json file name
with open(output_file_path, 'w', encoding='utf-8') as file:
    json.dump(processed_data, file, ensure_ascii=False, indent=4)

print("Number of data greater than 10240:", count)