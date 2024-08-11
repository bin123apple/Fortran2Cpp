#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("data.bin", std::ios::binary);
    if (!file) {
        std::cerr << "Cannot open file!" << std::endl;
        return 1;
    }

    float num;
    if (!file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        std::cerr << "Read error!" << std::endl;
        return 1;
    }

    std::cout << "Read number: " << num << std::endl;
    return 0;
}