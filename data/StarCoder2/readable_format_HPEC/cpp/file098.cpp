#include <iostream>
#include <fstream>
#include <omp.h>

int main() {
    const int len = 1000;
    int a[len];
    bool exist;
    std::string filename = "mytempfile.txt";
    std::ofstream file;

    // Initialize array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusting for 0-based indexing in C++
    }

    // Check if the file exists
    exist = std::ifstream(filename).good();

    // Open the file
    if (exist) {
        file.open(filename, std::ios::app); // Append mode
    } else {
        file.open(filename, std::ios::out); // New mode
    }

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Parallel loop to write to the file
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        file << a[i] << std::endl;
    }

    // Close the file and delete it
    file.close();
    if (remove(filename.c_str())!= 0) {
        std::cerr << "Error deleting the file." << std::endl;
    }

    return 0;
}
