#include <iostream>
#include <string>

int main() {
    // Equivalent of character *7 str in Fortran
    std::string str = "abcdefg";
    
    // Equivalent of integer array(7) in Fortran
    int array[7];
    for(int i = 0; i < 7; i++) {
        array[i] = i + 1; // Arrays in C++ are 0-based, so we add 1
    }
    
    // Demonstrating string slicing in C++
    // str(2:4) in Fortran is equivalent to getting a substring starting at index 1 with length 3 in C++
    std::cout << str.substr(1, 3) << std::endl;

    // str(:3) in Fortran, getting a substring from the beginning to index 2 in C++ (0-based indexing)
    std::cout << str.substr(0, 3) << std::endl;

    // str(5:) in Fortran, getting a substring from index 4 to the end in C++
    std::cout << str.substr(4) << std::endl;

    // str(:) in Fortran, representing the whole string in C++, just output the string as is
    std::cout << str << std::endl;

    return 0;
}