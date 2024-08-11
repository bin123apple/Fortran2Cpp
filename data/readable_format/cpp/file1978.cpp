#include <iostream>
#include <string>

int main() {
    std::string str = "abcdefg";
    int array[7];

    for (int i = 0; i < 7; ++i) {
        array[i] = i + 1;
    }

    // In C++, substrings are handled with the substr function.
    // substr takes two arguments: the starting index and the length of the substring.
    std::cout << str.substr(1, 3) << std::endl; // Equivalent to str(2:4) in Fortran, note that indices in C++ are 0-based.
    std::cout << str.substr(0, 3) << std::endl; // Equivalent to str(:3) in Fortran.
    std::cout << str.substr(4) << std::endl;    // Equivalent to str(5:) in Fortran, by default substr takes the rest of the string if the length is not specified.
    std::cout << str << std::endl;              // Equivalent to just str(:) in Fortran, which prints the whole string.

    return 0;
}