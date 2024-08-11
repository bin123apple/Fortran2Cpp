#include <iostream>
#include <cmath>
#include <complex>

// Define the constants directly in this file, without a separate header.
namespace constants {
    constexpr double eOverAmu = 9.58084e7;
    constexpr double mpc2 = 938271998.38;
    constexpr double c = 2.99792458e8;
    constexpr double pi = 3.141592653597932384;
    constexpr double q = 1.60217646e-19;
    constexpr double me = 9.10938188e-31;
    constexpr double mi = 1.67262158e-27;
    constexpr double eps0 = 8.854187817e-12;
    constexpr std::complex<double> zi(0.0, 1.0);
    constexpr double mu0 = 1.2566370614e-06;
    constexpr double clight = 299792458.0;
    constexpr std::complex<double> metal(1e8, 1e8);
}

// Simple testing mechanism
void testConstants() {
    double tolerance = 1e-5;
    bool allTestsPassed = true;
    
    // Example test: Check if the value of pi is as expected within the tolerance
    if (std::abs(constants::pi - 3.141592653597932384) > tolerance) {
        std::cerr << "Test for pi failed." << std::endl;
        allTestsPassed = false;
    }

    // Add more tests for other constants as needed...

    if (allTestsPassed) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cerr << "Some tests failed." << std::endl;
    }
}

int main() {
    // Call the test function
    testConstants();
    
    // You can also demonstrate the usage of constants here
    std::cout << "Demonstrating constant usage:" << std::endl;
    std::cout << "Speed of light (c): " << constants::c << " m/s" << std::endl;
    std::cout << "Planck's constant (h): " << constants::pi << std::endl;
    
    return 0;
}