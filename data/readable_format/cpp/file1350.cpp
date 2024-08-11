#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("output_cpp.txt");
    
    // Initialize the string 'a' with "cono" followed by 150 spaces
    std::string a = "cono" + std::string(150, ' ');

    // Writing the output to the file with proper string concatenation
    outFile << "a============" << std::endl;
    outFile << a << "fin" << std::endl;

    auto trimmedA = a;
    // Trimming the right side of the string 'a'
    trimmedA.erase(trimmedA.find_last_not_of(" ") + 1);

    // Writing the trimmed string to the file
    outFile << "trim(a)============" << std::endl;
    outFile << trimmedA << "fin" << std::endl;

    // Assigning the trimmed string to 'b'
    std::string b = trimmedA;

    // Writing the string 'b' to the file
    outFile << "b==========" << std::endl;
    outFile << b << "fin" << std::endl;

    outFile.close();
    return 0;
}