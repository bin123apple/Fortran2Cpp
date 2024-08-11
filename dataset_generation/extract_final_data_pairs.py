import re
import json
import os

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

file_path = '/home/uconn/BinLei/F2C-Translator/data/F2C_dialogue_25K.json'  # 输入的 JSON 文件路径
cpp_output_directory = '/home/uconn/BinLei/F2C-Translator/data/readable_format/cpp'  # 用于保存 C++ 代码的文件夹路径
fortran_output_directory = '/home/uconn/BinLei/F2C-Translator/data/readable_format/fortran'  # 用于保存 Fortran 代码的文件夹路径

# 创建保存文件的文件夹，如果它们不存在
if not os.path.exists(cpp_output_directory):
    os.makedirs(cpp_output_directory)

if not os.path.exists(fortran_output_directory):
    os.makedirs(fortran_output_directory)

with open(file_path, 'r', encoding='utf-8') as f:
    datas = json.load(f)
    cleaned_dataset = []
    for index in range(len(datas)):
        data = datas[index]
        cpp_code, fortran_code, first_sentence = extract_code(data)
        
        # 将 C++ 代码保存到 .cpp 文件中
        cpp_filename = os.path.join(cpp_output_directory, f"file{index:03d}.cpp")
        with open(cpp_filename, 'w', encoding='utf-8') as cpp_file:
            cpp_file.write(cpp_code)
        
        # 将 Fortran 代码保存到 .f90 文件中
        fortran_filename = os.path.join(fortran_output_directory, f"file{index:03d}.f90")
        with open(fortran_filename, 'w', encoding='utf-8') as fortran_file:
            fortran_file.write(fortran_code)
        
        cleaned_data = {
            "id": index,
            "messages": [
                {"role": "user", "content": first_sentence + "\n\n" + fortran_code },
                {"role": "assistant", "content": cpp_code }
            ]
        }
        cleaned_dataset.append(cleaned_data)
        
        if index % 1000 == 0:
            print(f"index: {index}")
            print("C++ Code:\n", cpp_code)
            print("Fortran Code:\n", fortran_code)
