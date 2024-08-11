#include <iostream>

// Forward declaration of TT to be used in the function pointer
void TT(float x);

// The DD function takes a function pointer as its parameter
// The function pointer points to a function that takes a float and returns void
void DD(void (*F)(float)) {
    F(0); // Example call to the function pointer, passing 0 as an argument
}

// Definition of TT, matching the function pointer signature
void TT(float x) {
    // Function body would go here. It's empty in the Fortran example.
}

int main() {
    // Call DD with TT as the argument
    DD(TT);

    return 0;
}