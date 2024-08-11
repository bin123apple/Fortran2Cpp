#include <iostream>
#include <array>
#include <string>

void printArray() {
    std::array<std::string, 2> arr = {"a", "bb"};
    for (const auto& str : arr) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

int main() {
    printArray();
    return 0;
}