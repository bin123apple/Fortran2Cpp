#include <iostream>

int main() {
    float i = 9.9f; // 'f' to ensure float literal
    
    do {
        if (i > 7.7f) {
            break; // Exit the loop, equivalent to 'exit i' in Fortran
        } else {
            i = 2.2f;
        }
    // A do-while loop that runs once simulates the Fortran block
    } while (false);
    
    std::cout << i << std::endl;
    return 0;
}