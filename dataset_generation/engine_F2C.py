"""
This is the code for Fortran to C++ code translation. Using GPT-4 as the teacher model.

"""
# import sys
# sys.path.append('..')
import os
import glob
import json
import pandas as pd
import subprocess
import tiktoken
from datasets import load_dataset

from utils.prompt import * 
from utils.model_utils import *


def generate_str_answer_gpt(input_prompt_gpt,max_tokens,gpt_model = "gpt-4-0125-preview"):
    messages = []
    message = {
        "role": "user",
        "content": input_prompt_gpt
    }
    messages.append(message)
    answer = generate_from_GPT(key,prompts=messages, 
                                    max_tokens=max_tokens, 
                                    model=gpt_model, 
                                    n=1)[0]["message"]["content"]
    return answer


def fur_modification(history, ser_messages, modification_prompt, max_tokens = 4096):
    m_ser = {
        "role": "user",
        "content": modification_prompt
    }
    history.append(m_ser)
    ser_messages.append(m_ser)
    m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
                                max_tokens=max_tokens, 
                                model="gpt-4-0125-preview", 
                                n=1)[0]["message"]
    ser_answer = m_ser_gpt["content"]    
    ser_messages.append(m_ser_gpt)
    m_his = {
        "role": "assistant",
        "content": f"{ser_answer}"
    }
    history.append(m_his)


def add_to_json(history, file_path='dialogues.json'):
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            try:
                data = json.load(file)
            except json.JSONDecodeError:  
                data = []
    else:
        data = []

    data.append(history)

    with open(file_path, 'w') as file:
        json.dump(data, file, indent=4)
       
        
def add_to_json(history, file_path='dialogues.json'):
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            try:
                dialogues = json.load(file)
            except json.JSONDecodeError:
                dialogues = []
    else:
        dialogues = []

    new_id = 1 if not dialogues else dialogues[-1]["id"] + 1

    new_dialogue = {
        "id": new_id,
        "messages": history
    }
    dialogues.append(new_dialogue)
    
    with open(file_path, 'w') as file:
        json.dump(dialogues, file, indent=4)
     

def run_codes(fortran_folder, f_code_exe, cpp_folder, c_code_exe, timeout_seconds=20):
    fortran_file_path = os.path.join(fortran_folder, 'test.f90')
    with open(fortran_file_path, 'w') as file:
        file.write(f_code_exe)

    cpp_file_path = os.path.join(cpp_folder, 'test.cpp')
    with open(cpp_file_path, 'w') as file:
        file.write(c_code_exe)

    fortran_compile_cmd = f'gfortran -fopenmp -J {fortran_folder} -o {fortran_folder}/test {fortran_file_path}'
    fortran_compile_process = subprocess.run(fortran_compile_cmd, 
                                                shell=True, 
                                                capture_output=True,
                                                timeout=timeout_seconds)
    fortran_stderr = fortran_compile_process.stderr
    fortran_stdout = fortran_compile_process.stdout
    if fortran_compile_process.returncode != 0:
        fortran_p_f = False
    else:
        fortran_p_f = True  
        fortran_run_cmd = f'{fortran_folder}/test'
        try:
            fortran_run_process = subprocess.run(fortran_run_cmd, 
                                                    shell=True, 
                                                    capture_output=True,
                                                    timeout=timeout_seconds)
            fortran_stdout = fortran_run_process.stdout.decode('utf-8', 'replace')
            fortran_stderr = fortran_run_process.stderr.decode('utf-8', 'replace')
        except subprocess.TimeoutExpired: # avoid infinite loop
            fortran_p_f = False
            fortran_stdout = ''
            fortran_stderr = b'It seems to go into an infinite loop! Fortran execution timed out.'
        # delete generated .mod files
        mod_files = glob.glob(f'{fortran_folder}/*.mod')
        for file in mod_files:
            os.remove(file)
    cpp_compile_cmd = f'g++ -fopenmp {cpp_file_path} -lgtest -lgtest_main -pthread -o {cpp_folder}/test'
    cpp_compile_process = subprocess.run(cpp_compile_cmd, 
                                            shell=True, 
                                            capture_output=True,
                                            timeout=timeout_seconds)
    cpp_stderr = cpp_compile_process.stderr
    cpp_stdout = cpp_compile_process.stdout
    if cpp_compile_process.returncode != 0:
        cpp_p_f = False
    else:
        cpp_p_f = True  
        cpp_run_cmd = f'{cpp_folder}/test'
        try:
            cpp_run_process = subprocess.run(cpp_run_cmd, 
                                                shell=True, 
                                                capture_output=True,
                                                timeout=timeout_seconds)    
            cpp_stdout = cpp_run_process.stdout.decode('utf-8', 'replace')
            cpp_stderr = cpp_run_process.stderr.decode('utf-8', 'replace')
        except subprocess.TimeoutExpired: # avoid infinite loop
            cpp_p_f = False
            cpp_stdout = ''
            cpp_stderr = b'It seems to go into an infinite loop! C++ execution timed out.'
    return fortran_stdout, fortran_stderr, fortran_p_f, cpp_stdout, cpp_stderr, cpp_p_f


def extract_codes(f_code_exe, c_code_exe, Str_Exe):
    fortran_start = Str_Exe.find("```fortran") + 10
    if fortran_start != 9:
        fortran_end = Str_Exe.find("```", fortran_start)
        f_code_exe = Str_Exe[fortran_start:fortran_end].strip()
        
    cpp_start = Str_Exe.find("```cpp") + 6
    if cpp_start != 5:
        cpp_end = Str_Exe.find("```", cpp_start)
        c_code_exe = Str_Exe[cpp_start:cpp_end].strip()   

    # try:
    #     f_code_exe
    # except NameError:
    #     f_code_exe = ""

    # try:
    #     c_code_exe
    # except NameError:
    #     c_code_exe = ""
    
    return f_code_exe, c_code_exe

def update_code_from_history(f_code_exe, c_code_exe, history):
    Str_Exe = history[-1]["content"]
    Str_Exe = Str_Exe.encode().decode('unicode_escape')
    f_code_exe, c_code_exe = extract_codes(f_code_exe, c_code_exe, Str_Exe)
    return f_code_exe, c_code_exe
    

def Ai_chat_with_Ai(key,fortran_code, max_tokens, gpt_model = "gpt-4-0125-preview",turns_limitation = 3):
    qer_messages = []
    ser_messages = []
    history = []
    
    # define the role of questioner
    m_qer = {
        "role": "system",
        "content": Instruction_qer
    }    
    qer_messages.append(m_qer) # system role defined
    
    # Start the conversation
    m_qer = {
        "role": "user",
        "content": q_ask_s_translation.format(fortran_code = fortran_code)
    }  
    qer_messages.append(m_qer) # user provide the question
    
    # Questioner ask for the C++ translation
    m_qer_gpt = generate_from_GPT(key,prompts=qer_messages, 
                                max_tokens=max_tokens, 
                                model=gpt_model, 
                                n=1)[0]["message"]
    qer_answer = m_qer_gpt["content"]
    qer_messages.append(m_qer_gpt)
    print(f"qer asks for the C++ translation:\n{qer_answer}")
    # print("qer_messages after Questioner ask for the C++ translation", qer_messages)
    
    # Solver generate the C++ translation
    m_ser = {
        "role": "user",
        "content": f"{qer_answer}"
    }
    ser_messages.append(m_ser)
    history.append(m_ser)
    m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
                                max_tokens=max_tokens, 
                                model=gpt_model, 
                                n=1)[0]["message"]
    ser_answer = m_ser_gpt["content"]
    print(f"Solver generate the C++ translation:\n{ser_answer}")
    ser_messages.append(m_ser_gpt)
    m_his = {
        "role": "assistant",
        "content": f"{ser_answer}"
    }
    history.append(m_his)  
    
    # Questioner ask for the unit test
    m_qer = {
        "role": "user",
        "content": q_ask_s_unit_test.format(ser_answer = ser_answer)
    }  
    qer_messages.append(m_qer)  
    m_qer_gpt = generate_from_GPT(key,prompts=qer_messages, 
                                max_tokens=max_tokens, 
                                model=gpt_model, 
                                n=1)[0]["message"]
    qer_answer = m_qer_gpt["content"] 
    print(f"Questioner ask for the unit test:\n{qer_answer}")   
    qer_messages.append(m_qer_gpt)
    
    # Solver generate the unit test
    m_ser = {
        "role": "user",
        "content": f"{qer_answer}"
    }
    ser_messages.append(m_ser)
    history.append(m_ser)
    m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
                                max_tokens=max_tokens, 
                                model=gpt_model, 
                                n=1)[0]["message"]
    ser_answer = m_ser_gpt["content"]    
    print(f"Solver generate the unit test:\n{ser_answer}")   
    ser_messages_init = ser_messages
    ser_messages.append(m_ser_gpt)
    m_his = {
        "role": "assistant",
        "content": f"{ser_answer}"
    }
    history.append(m_his)  
    
    """
    Compile and execute the unit test codes
    """
    f_code_exe = ''
    c_code_exe = ''
    f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)    
    
    for turn in range(turns_limitation):
        print(f"Runing modification {turn}th turn")
        # Initialize the solver message to avoid the potential impact from previous wrong answers
        Init_solver = Init_solver_prompt.format(fortran_code = f_code_exe, cpp_code = c_code_exe)
        ser_message_unit_test = {
        "role": "assistant",
        "content": f"{Init_solver}"
        }
        ser_messages_init_copy = ser_messages_init.copy()
        ser_messages_init_copy.append(ser_message_unit_test)
        ser_messages = ser_messages_init_copy
        # Extract compile and execute fortran and cpp unit test
        fortran_folder = '/home/uconn/BinLei/F2C-Translator/sandbox/fortran'
        cpp_folder = '/home/uconn/BinLei/F2C-Translator/sandbox/cpp'
        
        os.makedirs(fortran_folder, exist_ok=True)
        os.makedirs(cpp_folder, exist_ok=True)
        print("fortran code that need to be executed:\n",f_code_exe)    
        print("c++ code that need to be executed:\n",c_code_exe)  
        fortran_stdout, fortran_stderr, fortran_p_f, cpp_stdout, cpp_stderr, cpp_p_f = run_codes(fortran_folder, f_code_exe, cpp_folder, c_code_exe)
   
        fortran_compile_result = f"Fortran Stdout: {fortran_stdout}\nFortran Stderr: {fortran_stderr}"
        cpp_compile_result = f"C++ Stdout: {cpp_stdout}\nC++ Stderr: {cpp_stderr}"   
        print(f"fortran compile result in {turn}th turn:", fortran_compile_result)
        print(f"cpp compile result in {turn}th turn:", cpp_compile_result)
        
        # further modification / end
        break_outer_loop = False
        if fortran_p_f == False: # Modify fortran
            
            # Missing header files error
            if b"undefined reference to" in fortran_stderr or b"No such file or directory" in fortran_stderr:
                modification_prompt = combine_header_files_fortran.format(compile_result = f"Fortran Compile Stderr:{fortran_stderr}")
                try:
                    fur_modification(history, 
                            ser_messages, 
                            modification_prompt)
                except:
                    break
                print("Add fortran head file ",history[-1]["content"]) 
                f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)
                
            # Other errors
            else:
                modification_prompt = ff_ct_further_modification.format(fortran_compile_result = fortran_compile_result)
                try:
                    fur_modification(history, 
                                        ser_messages, 
                                        modification_prompt)   
                except:
                    break 
                print("ff_ct gpt answer",history[-1]["content"])      
                f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)        
        
        if cpp_p_f == False: # Modify cpp
            
            # Missing header files error
            if b"undefined reference to" in cpp_stderr or b"No such file or directory" in cpp_stderr:
                modification_prompt = combine_header_files_cpp.format(compile_result = f"C++ Compile Stderr:{cpp_stderr}")
                try:
                    fur_modification(history, 
                            ser_messages, 
                            modification_prompt)
                except:
                    break 
                print("Add c++ head file ",history[-1]["content"]) 
                f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)  
            
            #  Missing terminating error
            elif b'missing terminating " character' in cpp_stderr:         
                modification_prompt = missing_terminating.format(cpp_compile_result = cpp_compile_result)
                try:
                    fur_modification(history, 
                                        ser_messages, 
                                        modification_prompt)   
                except:
                    break                  
                print("Missing terminating",history[-1]["content"])     
                f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)   
                 
            # Other errors
            else:
                modification_prompt = ft_cf_further_modification.format(cpp_compile_result = cpp_compile_result)
                try:
                    fur_modification(history, 
                                        ser_messages, 
                                        modification_prompt)     
                except:
                    break                 
                print("ft_cf gpt answer",history[-1]["content"])     
                f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)                               
                 
        if fortran_p_f == True and cpp_p_f == True:
            decision_prompt = ft_ct_further_check.format(fortran_compile_result = fortran_compile_result,
                                                         cpp_compile_result = cpp_compile_result) 
            try:
                fur_modification(history, 
                                    ser_messages, 
                                    decision_prompt)  
            except:
                break
            print("ft_ct gpt answer",history[-1]["content"])
            f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)              
            for end_check in range(2):
                Str_y_n = history[-1]["content"]    
                if "yes" in Str_y_n.lower():
                    end_prompt = end_prompt_
                    fur_modification(history, 
                                        ser_messages, 
                                        end_prompt)
                    print("yes",history[-1]["content"])
                    break_outer_loop = True # break outer layer
                    f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)                     
                    break
                elif "no" in Str_y_n.lower():
                    further_modification = further_modification_
                    fur_modification(history, 
                                        ser_messages, 
                                        further_modification)
                    print("no",history[-1]["content"])
                    f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)                     
                    break
                else:
                    clear_prompt = clear_prompt_       
                    fur_modification(history, 
                                        ser_messages, 
                                        clear_prompt)                             
                    print("unclear",history[-1]["content"])
                    f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)                 
        if break_outer_loop:
            break
                
    return history,break_outer_loop



def generate_data(key, input_dataset, output_file, gpt_model="gpt-4"):
    
    # initialize the list for holding each row of the dataset
    dialogues = []
    
    # select source fortran codes from a dataset
    for idx in range(len(input_dataset['code'])):
        print(f"Working on the {idx}th code...")
        fortran_code = input_dataset['code'][idx]
        
        # Count the length of the input tokens
        encoding = tiktoken.encoding_for_model("gpt-4")
        token_count = len(encoding.encode(fortran_code + "\n",disallowed_special=()))
        
        # set a upper limit of the length of the input prompt and generate the answer
        if token_count < 3700:
            max_tokens= 256 + token_count
            
            # Step 1: delete the comments of the source fortran code
            fortran_wo_com = delete_comments.format(Fortran_Code = fortran_code)
            fortran_wo_com = generate_str_answer_gpt(fortran_wo_com, max_tokens)
            fortran_wo_com = fortran_wo_com.encode().decode('unicode_escape','replace')
            print(f"fortran_wo_com:\n{fortran_wo_com}")
            encoding = tiktoken.encoding_for_model("gpt-4")
            token_count = len(encoding.encode(fortran_wo_com,disallowed_special=()))     
            print("fortran_wo_com length", token_count)
            # control the length
            if token_count < 600:     
                fortran_start = fortran_wo_com.find("```fortran") + 10
                if fortran_start == 9:
                    print("Did not find the fortran code!")
                    continue
                else:
                    fortran_end = fortran_wo_com.find("```", fortran_start)
                    fortran_wo_com = fortran_wo_com[fortran_start:fortran_end].strip()
                try:
                    fortran_wo_com
                except NameError as e:
                    print("Did not find the fortran code!", str(e))
                    continue 
                
                # Step 2: Remove non-executable code 
                skip_code = False
                
                # Remove code that contains external file reading operations
                keywords_to_remove = ['OPEN', 'READ', 'WRITE', 'CLOSE']
                if any(keyword in fortran_wo_com for keyword in keywords_to_remove):
                    skip_code = True
                    print("This fortran code contains external file reading operations, it will be skipped!")

                # Remove code that contains operations for user input
                keywords_to_remove = ['GET_ENVIRONMENT_VARIABLE', 
                                      'READ', 
                                      'GET_COMMAND_ARGUMENT', 
                                      'IARGC',
                                      'GETARG']
                             
                if any(keyword in fortran_wo_com.upper() for keyword in keywords_to_remove):
                    skip_code = True
                    print("This Fortran code contains operations for user input, it will be skipped!")    
                    
                # Remove Fortran code containing undefined external functions
                if_contain_ext = if_contain_ext_prompt.format(Fortran_Code = fortran_wo_com)
                if_contain_ext = generate_str_answer_gpt(if_contain_ext, max_tokens)
                if_contain_ext = if_contain_ext.encode().decode('unicode_escape')    
                if "no" not in if_contain_ext.lower():      
                    skip_code = True             
                    print("This Fortran code contains undefined external functions, it will be skipped!")          
                                               
                # Step 3: get function of the code; translated cpp code and explanation    
                if skip_code == False:
                    try:
                        history,break_outer_loop = Ai_chat_with_Ai(key,
                                                fortran_wo_com, 
                                                max_tokens = 4096, 
                                                gpt_model = gpt_model,
                                                turns_limitation = 7)
                    except:
                        print("Skip!", str(e))
                        continue 
                    if break_outer_loop:
                        add_to_json(history, output_file)
            

    
    
# def inference(eval_csv_path, model_name_or_path, device_num=3):
#     with open(eval_csv_path, 'r') as file:
#         csv_reader = csv.reader(file)
#         next(csv_reader, None)  
#         row_count = sum(1 for row in csv_reader)
    
#     # read eval_data from csv file
#     eval_data = pd.read_csv(eval_csv_path)
#     res=[-1]*row_count

#     tokenizer, model = load_local_model(model_name_or_path, device_num=device_num)
#     if tokenizer.pad_token is None:
#         tokenizer.pad_token = tokenizer.eos_token

#     for i in range(row_count):
#         # read eval data: fortran code and cpp code
#         fortran_code = eval_data['fortran'][i]
#         cpp_code = eval_data['cpp'][i]

#         # get model output
#         input_prompt_local = "Translate the following Fortran code to cpp " + fortran_code
#         try:
#             predicted_answer = generate_from_local_model(input_prompt_local, 2*len(input_prompt_local), tokenizer, model, device_num, n=1, max_prompt_length=1024)[0]                
#             print("predicted_answer",predicted_answer) # Print the generated data
            
#             # assert: compiler
#             yes_or_no_compiler, reason = check_by_compiler(predicted_answer)
#             if yes_or_no_compiler == True:
#                 # assert GPT4
#                 messages = []
#                 message = {
#                 "role": "user",
#                 "content": Asserter_Y_N.format(Fortran_Code=fortran_code, Cpp_Code=predicted_answer)}
#                 messages.append(message)
#                 yes_or_no, reason = check_code_translation(i,messages)
#                 if yes_or_no == True:
#                     res[i] = 1
#                 else:
#                     res[i] = 0
#             else:
#                 res[i] = 0
#         except Exception as e:
#             print(f"An error occurred: {e}")
#     print("RATIO:", res.count(1)/(res.count(1)+res.count(0)))
#     return res.count(1)/(res.count(1)+res.count(0))

if __name__ == "__main__":
    key = "" # Input your OpenAI Key
    
    # You can also use other datasets
    Fortran_dataset = load_dataset("codeparrot/github-code", "FORTRAN-all")
    data = Fortran_dataset["train"][78000:85000]
    
    output_file = "" # Output Json file
    generate_data(key, data, output_file, gpt_model="gpt-4o") # Need to change
    
    