#include <iostream>
#include <fstream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 1000;
    std::vector<int> a(len);
    bool exist;

    // Check if the file exists
    std::ifstream file("mytempfile.txt");
    exist = file.good();
    file.close();

    // Open the file in append mode if it exists, otherwise create a new file
    std::ofstream outFile;
    if (exist) {
        outFile.open("mytempfile.txt", std::ios::app);
    } else {
        outFile.open("mytempfile.txt");
    }

    if (!outFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Fill the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusting for 0-based indexing in C++
    }

    // Parallel write to the file
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        outFile << a[i] << std::endl;
    }

    outFile.close();

    // Delete the file if successful
    if (outFile.good()) {
        remove("mytempfile.txt");
    }

    return 0;
}
