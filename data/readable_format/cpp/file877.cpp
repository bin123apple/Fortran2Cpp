// C++ equivalent for Fortran's COMMON block /T/ and MODULE A22_MODULE
#include <iostream>

// Assuming 'A' in the COMMON block /T/ is of a type that could be represented as 'int'.
// You should change the type according to what 'A' represents in your Fortran code.
int A;

// Forward declaration of a function equivalent to Fortran subroutine.
void A22_4_WRONG();

int main() {
    // Initial setup or manipulation of 'A' could happen here or within any function.
    A = 0; // Example initialization

    A22_4_WRONG(); // Call the function equivalent to the Fortran subroutine.

    // Additional code here...

    return 0;
}

// Definition of the function.
void A22_4_WRONG() {
    // In the original Fortran code, this subroutine doesn't do anything.
    // This is where you would work with 'A' if needed.
    // For demonstration, let's just print 'A'
    std::cout << "A: " << A << std::endl;
}