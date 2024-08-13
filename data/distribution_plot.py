import os
import matplotlib.pyplot as plt

def count_lines_in_file(file_path):
    with open(file_path, 'r') as file:
        return sum(1 for line in file)

def collect_line_counts(directory):
    line_counts = []
    for filename in os.listdir(directory):
        if filename.endswith(".f90") or filename.endswith(".cpp"):  # Adjust file extensions as needed
            file_path = os.path.join(directory, filename)
            line_count = count_lines_in_file(file_path)
            line_counts.append(line_count)
    return line_counts

def plot_histogram(line_counts, title, x_label, y_label, output_file):
    plt.figure(figsize=(10, 6))
    plt.hist(line_counts, bins=20, color='skyblue', edgecolor='black')
    plt.title(title)
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.grid(True)
    plt.savefig(output_file)
    plt.show()

# Directories containing the Fortran and C++ files
fortran_directory = 'F2C-Translator/data/readable_format/fortran'
cpp_directory = 'F2C-Translator/data/readable_format/cpp'

# Collect line counts
fortran_line_counts = collect_line_counts(fortran_directory)
cpp_line_counts = collect_line_counts(cpp_directory)

# Plot histograms
plot_histogram(fortran_line_counts, 'Distribution of Fortran Source File Line Counts', 
               'Line Numbers', 'File Counts', 'fortran_histogram.png')
plot_histogram(cpp_line_counts, 'Distribution of C++ Source File Line Counts', 
               'Line Numbers', 'File Counts', 'cpp_histogram.png')
