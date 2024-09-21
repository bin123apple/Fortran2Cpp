import subprocess
import tempfile
import os

def compile_and_run_each_file(source_folder):
    results = []
    
    # Temporary directory to store temporary executable files
    with tempfile.TemporaryDirectory() as tmpdirname:
        compilable = 0
        executable = 0
        for index, filename in enumerate(os.listdir(source_folder)):
            file_path = os.path.join(source_folder, filename)
            if not file_path.endswith('.cpp'):
                continue  # Skip non-C++ files
            print(f"Working on {filename} ({index + 1})")
            
            executable_path = os.path.join(tmpdirname, f"temp_{index}")
            
            # Compile and run the C++ program
            compile_command = ["g++", file_path, "-o", executable_path]
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
                "File": filename,
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
source_folder = '/home/uconn/BinLei/F2C-Translator/data/readable_format/cpp'
result, compilable, executable = compile_and_run_each_file(source_folder)
print(f"Number of compilable: {compilable}")
print(f"Number of executable: {executable}")
for res in result:
    print(f"File {res['File']}: Compilation {res['Compilation']['Success']}, Run {res['Run']['Success']}")

