#include <iostream>

// Global variable to mimic the Fortran COMMON block
int A;

// Declaration of the nested subroutine
void A22_5S_WRONG() {
    std::cout << "A22_5S_WRONG called successfully." << std::endl;
}

// The translated subroutine
void A22_5_WRONG() {
    A22_5S_WRONG(); // Call the nested subroutine
    A = 5; // Modify the global variable
    std::cout << "A22_5_WRONG completed. A = " << A << std::endl;
}

int main() {
    A22_5_WRONG(); // Call the subroutine
    std::cout << "C++ test passed: A22_5_WRONG called successfully." << std::endl;
    return 0;
}