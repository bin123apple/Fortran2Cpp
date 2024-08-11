#include <iostream>
#include <fstream>
#include <vector>

// Function to write data to a file
void writeDataToFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const int& val : data) {
            outFile << val << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Could not open file for writing." << std::endl;
    }
}

// Function to read data from a file
std::vector<int> readDataFromFile(const std::string& filename) {
    std::vector<int> data;
    std::ifstream inFile(filename);
    int val;

    if (inFile.is_open()) {
        while (inFile >> val) {
            data.push_back(val);
        }
        inFile.close();
    } else {
        std::cerr << "Could not open file for reading." << std::endl;
    }

    return data;
}

int main() {
    std::string filename = "example.txt";
    std::vector<int> dataToWrite = {1, 2, 3, 4, 5};

    // Write data to file
    writeDataToFile(filename, dataToWrite);

    // Read data from file
    std::vector<int> dataRead = readDataFromFile(filename);

    // Print read data
    std::cout << "Data read from file:" << std::endl;
    for (const int& val : dataRead) {
        std::cout << val << std::endl;
    }

    return 0;
}