#include <iostream>
#include <string>

int main() {
    // Equivalent of Fortran's character(len=20) :: c
    std::string c = "     "; // Assigning 5 spaces to the string

    // Print the string
    std::cout << c << std::endl;

    return 0;
}