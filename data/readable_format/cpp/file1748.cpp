#include <iostream>
#include <cmath>

// Define the DLCTES function directly in this file
bool DLCTES(double ZR, double ZI, double D) {
    const double ZERO = 0.0;
    const double ONE = 1.0;

    if (D == ZERO) {
        return ZR < ZERO;
    } else {
        // std::copysign returns a value with the magnitude of the first argument and the sign of the second argument.
        // To replicate the Fortran SIGN behavior, we compare the signs of ONE with ZR and ONE with D.
        // If the signs are different, the expression evaluates to true; otherwise, false.
        return std::copysign(ONE, ZR) != std::copysign(ONE, D);
    }
}

// Main function to test DLCTES
int main() {
    std::cout << std::boolalpha; // Print bools as true/false instead of 1/0

    // Test cases
    std::cout << "Test 1: " << DLCTES(-1.0, 0.0, 0.0) << std::endl; // Expected: true
    std::cout << "Test 2: " << DLCTES(1.0, 0.0, -1.0) << std::endl; // Expected: true
    std::cout << "Test 3: " << DLCTES(-1.0, 0.0, 1.0) << std::endl; // Expected: false

    return 0;
}