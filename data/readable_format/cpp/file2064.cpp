#include <iostream>

// Function declaration
void S(int X, float Y) {
    // The subroutine body is empty in the original Fortran code.
    // You can add code here as needed.
}

int main() {
    // The original Fortran code attempts to call the subroutine with different types of arguments.
    // In C++, we must match the types exactly, so we cannot pass a floating-point number where an integer is expected.

    S(1, 2.0f); // This matches the signature of S.
    // S(1.1, 2); // This would cause a compilation error in C++, as 1.1 is a double and not an integer.
    S(1, 2.2f); // This is fine, as 2.2f is a float.
    // S(1.1, 2.2); // This would also cause a compilation error for the same reason as above.

    return 0;
}