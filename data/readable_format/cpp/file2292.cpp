#include <iostream>

// Function prototypes
void one();
void two();

// Namespace to mimic the Fortran module
namespace mod {
    void three();
    void four();
}

// Function definitions
void one() {
    // Equivalent to an empty Fortran subroutine.
}

void two() {
    // Equivalent to an empty Fortran subroutine.
}

namespace mod {
    void three() {
        two();  // Call subroutine two
    }

    void four() {
        one();  // Call subroutine one
    }
}

int main() {
    // Testing the functions
    mod::three();
    mod::four();
    return 0;
}