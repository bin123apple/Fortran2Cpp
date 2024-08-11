#include <iostream>

int main() {
    // In Fortran, `PARAMETER` arrays are constants, so we use `const` in C++.
    // Note that C++ arrays are 0-indexed, unlike Fortran's 1-indexed arrays.
    const int X[3] = {5, 5, 5}; // Initialize all elements to 5

    // Switch-case in C++ does not directly support range or array checking in cases,
    // so we use the first element as in the original Fortran code.
    switch (X[0]) {
        case 1:
            std::cout << "HI" << std::endl;
            break;
        default:
            std::cout << "BYE" << std::endl;
            break;
    }

    return 0;
}