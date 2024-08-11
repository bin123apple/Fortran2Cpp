#include <iostream>
#include <fstream>
#include <string>

// Assuming reportfileu is an std::ofstream object used globally in your application context.
std::ofstream reportfileu;

void finalizeOutput() {
    reportfileu << "</report>" << std::endl;
    reportfileu.close();
}

void checkFileContents(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    if (getline(file, line)) {
        if (line == "</report>") {
            std::cout << "Test passed." << std::endl;
        } else {
            std::cout << "Test failed - incorrect content." << std::endl;
        }
    } else {
        std::cout << "Test failed - could not read from file." << std::endl;
    }
    file.close();
}

int main() {
    const std::string testFileName = "testReportFile.xml";

    // Opening the file for writing
    reportfileu.open(testFileName, std::ofstream::out | std::ofstream::trunc);
    if (!reportfileu.is_open()) {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return 1;
    }

    finalizeOutput();
    checkFileContents(testFileName);

    return 0;
}