#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("test_file.txt");

    if (file.good()) {
        std::cout << "File exists." << std::endl;
    } else {
        std::cout << "File does not exist." << std::endl;
    }

    return 0;
}