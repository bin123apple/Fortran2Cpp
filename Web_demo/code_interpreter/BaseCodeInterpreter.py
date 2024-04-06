import os
import sys
import re
import subprocess

prj_root_path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(prj_root_path)


from utils.const import *

class BaseCodeInterpreter:
    def __init__(self):
        self.dialog = [
            {
                "role": "system",
                "content": CODE_INTERPRETER_SYSTEM_PROMPT,
            },
        ]

    @staticmethod
    def extract_code_blocks(text: str):
        pattern = r"```(?:python\n)?(.*?)```"  # Match optional 'python\n' but don't capture it
        code_blocks = re.findall(pattern, text, re.DOTALL)
        return [block.strip() for block in code_blocks]

    # def execute_code_and_return_output(self, code_str: str, nb):
    #     _, _ = nb.add_and_run(GUARD_CODE)
    #     outputs, error_flag = nb.add_and_run(code_str)
    #     return outputs, error_flag

    def execute_code_and_return_output(self, generated_code_block) -> str:
        code_blocks_output= {}
        sandbox_path = "/sandbox"
        file_map = {"python": "script.py", "cpp": "script.cpp", "fortran": "script.f90"}
        image_map = {"python": "python-sandbox", "cpp": "cpp-sandbox", "fortran": "fortran-sandbox"}
        dockerfile_map = {"python": "python/Dockerfile.python", "cpp": "cpp/Dockerfile.cpp", "fortran": "fortran/Dockerfile.fortran"}
        for lang, code in generated_code_block.items():
            
            file_name = file_map[lang]
            image_name = image_map[lang]
            
            print(f"Writing the script for {lang}...")
            file_path = f"{sandbox_path}/{lang}/{file_name}"
            with open(file_path, 'w') as file:
                file.write(code)
            
            # check and build the image
            print(f"Checking if the image for {lang}... exist")
            image_name = image_map[lang]
            check_command = ["docker", "images", "-q", image_name]
            image_exists = subprocess.run(check_command, capture_output=True, text=True).stdout.strip()
            
            if not image_exists:
                print(f"Creating the image for {lang}...")
                dockerfile_path = os.path.join(sandbox_path, dockerfile_map[lang])
                lang_sandbox_path = f"{sandbox_path}/{lang}/"
                build_command = ["docker", "build", "-t", image_name, "-f", dockerfile_path, lang_sandbox_path]
                build_result = subprocess.run(build_command, capture_output=True, text=True)
                if build_result.returncode != 0:
                    print(f"Failed to build image {image_name}: {build_result.stderr}")
                    code_blocks_output[lang] = f"Failed to build image {image_name}: {build_result.stderr}"
                    continue
            
            
            print(f"Running the script for {lang} in the sandbox...")
            script_path = f"{sandbox_path}/{lang}/compile_run.sh"
            chmod_command = ["chmod", "+x", script_path]
            chmod_result = subprocess.run(chmod_command, capture_output=True, text=True)
            volume_mount = f"{sandbox_path}/{lang}:/app"
            command = ["docker", "run", "--rm", "-v", volume_mount, image_name]
            # command = ["docker", "run", "--rm", image_name]
            result = subprocess.run(command, capture_output=True, text=True)
            
            if result.returncode == 0: 
                code_blocks_output[lang] = result.stdout 
            else: 
                code_blocks_output[lang] = result.stderr
        return code_blocks_output