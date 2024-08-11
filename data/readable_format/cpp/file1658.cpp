#include <iostream>

namespace test { // Translating Fortran module to C++ namespace

    void oacc1() { // Translating Fortran subroutine to C++ function
        int i; // Translating Fortran integer to C++ int
        float pointee; // Translating Fortran real to C++ float
        float* ptr = &pointee; // Translating Fortran pointer to C++ pointer

        // Translating Fortran do loops to C++ for loops
        for(i = 1; i <= 5; i++) {
        }

        for(i = 1; i <= 5; i++) {
        }

        for(i = 1; i <= 5; i++) {
        }

        for(i = 1; i <= 5; i++) {
        }
    }

} // end of namespace test

int main() {
    test::oacc1(); // Calling the translated subroutine
    return 0;
}