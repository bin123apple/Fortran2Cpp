#include <iostream>
#include <cstdlib> // For exit()

// Since the subroutine doesn't return a value, we use void in C++
void foo(int i) {
    char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                          '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    // Accessing the array with i, which is already 0-based.
    char c = hex_chars[i];
    
    // C++ uses '!=' for inequality. 'std::exit' is used to terminate the program.
    if (c != '3') std::exit(1);
}

int main() {
    // Call the function with 3, similar to calling the subroutine in Fortran.
    foo(3);
    return 0;
}