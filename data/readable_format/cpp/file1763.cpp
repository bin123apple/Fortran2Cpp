#include <iostream>
#include <array>
#include <string>

int main() {
    std::string str = "abcdefg";
    std::array<int, 7> array;

    // Initialize the array
    for (int i = 0; i < 7; ++i) {
        array[i] = i + 1;
    }

    // Demonstrating string slicing in C++
    // Note: substr takes the start position and length of the substring, not the end position.
    std::cout << str.substr(1, 3) << std::endl; // str(2:4) in Fortran
    std::cout << str.substr(0, 3) << std::endl; // str(:3) in Fortran
    std::cout << str.substr(4) << std::endl;    // str(5:) in Fortran
    std::cout << str << std::endl;              // str(:) in Fortran

    return 0;
}