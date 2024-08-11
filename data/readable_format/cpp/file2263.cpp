#include <iostream>
#include <cstring>

int main() {
    const char a[3] = "12"; // Fortran's character*2 corresponds to a 2-character array, plus one for the null terminator
    char b[5];             // Fortran's character*4 corresponds to a 4-character array, plus one for the null terminator

    std::strncpy(b, a, 4); // Copy the string from a to b, up to 4 characters
    b[4] = '\0';           // Ensure null termination

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}