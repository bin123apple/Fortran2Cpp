#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Function declaration
void writeVector(const std::vector<double>& ad, int neq, int number);

int main() {
    // Test cases
    std::vector<std::vector<double>> vectors = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    std::vector<int> nums = {1, 2, 3};

    for(size_t i = 0; i < nums.size(); ++i) {
        writeVector(vectors[i], vectors[i].size(), nums[i]);
        std::string fileName = "vector_" + std::string(1, char(nums[i] + 96)) + ".out";
        std::ifstream file(fileName);
        std::string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << fileName << std::endl;
        }
    }

    return 0;
}

// Function definition
void writeVector(const std::vector<double>& ad, int neq, int number) {
    std::string name = "vector_" + std::string(1, char(number + 96)) + ".out";

    std::ofstream outFile(name); // Automatically opens the file
    if (!outFile) {
        std::cerr << "Failed to open file: " << name << std::endl;
        return;
    }

    outFile << "vector number " << number << std::endl;
    for (int i = 0; i < neq; ++i) {
        outFile << "row " << (i+1) << " value " << ad[i] << std::endl;
    }

    outFile.close(); // Automatically called by the destructor if not explicitly called
}