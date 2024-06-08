import re
import json

def extract_code(data):
    
    cplusplus_code = None
    fortran_code = None
    
    messages = data['messages']
    cpp_tag = '```cpp'
    fortran_tag = '```fortran'
    
    for i in range(len(messages) - 2, -1, -1):
        message = messages[i]['content']
        if cplusplus_code is None and cpp_tag in message:
            cpp_start = message.find(cpp_tag) + len(cpp_tag)
            cpp_end = message.find('```', cpp_start)
            cplusplus_code = message[cpp_start:cpp_end].strip()
        
        if fortran_code is None and fortran_tag in message:
            fortran_start = message.find(fortran_tag) + len(fortran_tag)
            fortran_end = message.find('```', fortran_start)
            fortran_code = message[fortran_start:fortran_end].strip()
        
        if cplusplus_code is not None and fortran_code is not None:
            break
    
    first_content = messages[0]["content"]
    match = re.search(r'([^.!?]*[.!?])', first_content)
    if match:
        first_sentence = match.group(1).strip()
    else:
        print("Warning: Did not find the first sentence!")
        first_sentence = ""

    return cplusplus_code, fortran_code, first_sentence

file_path = '' # Input Json file
output_file_path = "" # Output Json file
with open(file_path, 'r', encoding='utf-8') as f:
    datas = json.load(f)
    cleaned_dataset = []
    for index in range(len(datas)):
        data = datas[index]
        cpp_code, fortran_code, first_sentence = extract_code(data)
        cleaned_data = {"id":index,
        "messages":[{"role": "user",
                    "content":first_sentence + "\n\n" + fortran_code },
                    {"role": "assistant",
                     "content": cpp_code 
                    }]
                    }
        cleaned_dataset.append(cleaned_data)
        if index % 1000 == 0:
            print(f"index:{index}")
            print("C++ Code:\n", cpp_code)
            print("Fortran Code:\n", fortran_code)

with open(output_file_path, 'w', encoding='utf-8') as f:
    json.dump(cleaned_dataset, f, ensure_ascii=False, indent=4)
