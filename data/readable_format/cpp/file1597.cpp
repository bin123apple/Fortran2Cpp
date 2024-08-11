#include <iostream>

// Namespace to mimic Fortran's COMMON block
namespace COMMONNAME {
    // Equivalent to INTEGER :: A
    int A;
}

int main() {
    // Example usage of A
    COMMONNAME::A = 5;
    std::cout << "A = " << COMMONNAME::A << std::endl;
    return 0;
}