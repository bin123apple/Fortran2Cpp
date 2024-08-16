import subprocess
import tempfile
import os

def compile_and_run_each_line(source_file):
    results = []
    with open(source_file, 'r') as file:
        lines = file.readlines()
    
    # Temporary directory to store temporary source and executable files
    with tempfile.TemporaryDirectory() as tmpdirname:
        compilable = 0
        executable = 0
        for index, line in enumerate(lines):
            print(f"Working on {index}")
            # Create a temporary C++ source file
            cpp_source_path = os.path.join(tmpdirname, f"temp_{index}.cpp")
            executable_path = os.path.join(tmpdirname, f"temp_{index}")
            formatted_line = bytes(line, "utf-8").decode("unicode_escape")
            with open(cpp_source_path, 'w') as cpp_file:
                cpp_file.write(formatted_line)
            
            # Compile and run the C++ program
            compile_command = ["g++", cpp_source_path, "-o", executable_path]
            run_command = f"{executable_path}"
            
            try:
                compile_result = subprocess.run(compile_command, check=True, text=True, capture_output=True, timeout=10)
                compile_success = True
                compile_message = "Compilation successful."
                compilable += 1
            except subprocess.CalledProcessError as e:
                compile_success = False
                compile_message = f"Compilation failed: {e.stderr}"
            except subprocess.TimeoutExpired:
                run_success = False
                run_message = "Execution timed out."

            if compile_success and os.path.exists(executable_path):
                try:
                    run_result = subprocess.run(run_command, check=True, text=True, capture_output=True, timeout=5)
                    run_success = True
                    run_message = f"Run successful: {run_result.stdout}"
                    executable += 1
                except subprocess.CalledProcessError as e:
                    run_success = False
                    run_message = f"Run failed: {e.stderr}"
                except subprocess.TimeoutExpired:
                    run_success = False
                    run_message = "Execution timed out."
            else:
                run_success = False
                run_message = "Run skipped due to compilation failure."

            results.append({
                "Line": index + 1,
                "Compilation": {
                    "Success": compile_success,
                    "Message": compile_message
                },
                "Run": {
                    "Success": run_success,
                    "Message": run_message
                }
            })

    return results, compilable, executable

# Usage
source_file = '/home/uconn/BinLei/HPC_Dataset_test/Final_Results/GPT_4o_HPEC.txt'
result, compilable, executable = compile_and_run_each_line(source_file)
print(f"Number of compilable: {compilable}")
print(f"Number of executable: {executable}")
for res in result:
    print(f"Line {res['Line']}: Compilation {res['Compilation']['Success']}, Run {res['Run']['Success']}")
