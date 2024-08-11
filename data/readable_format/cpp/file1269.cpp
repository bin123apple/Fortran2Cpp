#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("test.xml");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    while (getline(file, line)) {
        std::cout << "Read line: " << line << std::endl;
    }

    file.close();
    std::cout << "File read successfully." << std::endl;

    return 0;
}