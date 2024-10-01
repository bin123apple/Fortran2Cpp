"""
The script reads the content of each .cpp file line by line.

If it finds a line that starts with a double quote ("), it merges that line with the previous line by removing the newline from the previous line and appending \\n.

It then writes the modified content back to the file.

    printf ("a[50][50]=%d
    ", a[50][50]);

It will be corrected to :
    printf ("a[50][50]=%d\n", a[50][50]);

""" 
import os

# Define the folder path containing your .cpp files
folder_path = "./cpp"

# Iterate through all files in the folder
for filename in os.listdir(folder_path):
    if filename.endswith(".cpp"):
        file_path = os.path.join(folder_path, filename)
        
        # Read the content of the .cpp file line by line
        with open(file_path, 'r') as file:
            lines = file.readlines()
        
        # Variable to store the fixed content
        fixed_lines = []
        
        # Iterate through each line to find and fix the lines starting with a quote
        for i, line in enumerate(lines):
            stripped_line = line.strip()
            
            # If a line starts with a double quote and there is a previous line
            if stripped_line.startswith('"') and i > 0:
                # Remove the newline from the previous line and add the current line after inserting \n
                fixed_lines[-1] = fixed_lines[-1].rstrip() + '\\n' + stripped_line + "\n"
            else:
                # Otherwise, just add the line as is
                fixed_lines.append(line)
        
        # Write the fixed content back to the .cpp file
        with open(file_path, 'w') as file:
            file.writelines(fixed_lines)
        
        print(f"Fixed {filename}")

print("Done fixing files.")
