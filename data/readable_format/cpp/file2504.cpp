#include <iostream>
#include <complex>
#include <cstdlib>

// Function that contains the logic to be tested
int foo() {
    std::complex<double> z0, z1, z2;

    z0 = std::complex<double>(0.0, 0.5);
    z1 = 1.0 / z0;
    if (z1 != std::complex<double>(0.0, -2.0)) {
        return 1;
    }

    z0 = 10.0 * z0;
    if (z0 != std::complex<double>(0.0, 5.0)) {
        return 2;
    }

    z2 = std::complex<double>(1.0, 2.0);
    z1 = z0 / z2;
    if (z1 != std::complex<double>(2.0, 1.0)) {
        return 3;
    }

    z1 = z0 * z2;
    if (z1 != std::complex<double>(-10.0, 5.0)) {
        return 4;
    }

    return 0; // Indicates success
}

// Simple test function to validate the foo() function
void test_foo() {
    if (foo() == 0) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

// Main function
int main() {
    test_foo(); // Run the test
    return 0;
}