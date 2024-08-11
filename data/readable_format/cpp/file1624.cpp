#include <iostream>
#include <cmath>
#include <cstdlib>

// Global variables to replicate the Fortran common block
double a, b, c;

// Initialize the variables
void initialize() {
    a = 3.0;
    b = 4.0;
    c = 5.0;
}

int main() {
    initialize(); // Initialize the variables with the values from the Fortran blockdata section

    const double eps = 0.00001;

    // Check if the variables are close to their expected values
    if (std::abs(a - 3.0) < eps && std::abs(b - 4.0) < eps && std::abs(c - 5.0) < eps) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NG" << std::endl;
        std::exit(1); // Exit with an error code
    }

    return 0;
}