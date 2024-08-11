#include <iostream>
#include <cmath> // For std::abs

// Define the constants within a namespace
namespace constants {
    constexpr double pi = 3.141592653589;
    constexpr double eps0 = 8.8541878176e-12;
    constexpr double mu0 = 4.0 * pi * 1e-7;
    constexpr double c0 = 2.997924580003e8;
    constexpr double eta0 = 3.767303134622e2;

    constexpr double radtodeg = 180.0 / pi;
    constexpr double degtorad = pi / 180.0;

    constexpr int prd_none = 1;
    constexpr int prd_2d = 2;
}

// Simple test function to check the validity of the constants
void testConstants() {
    using namespace constants;
    bool testPassed = true;
    
    // Using a simple lambda for repetitive checks
    auto check = [&](const char* name, double value, double expected, double tolerance = 1e-12) {
        if (std::abs(value - expected) > tolerance) {
            std::cout << "Test failed for " << name << ": Expected " << expected << ", got " << value << std::endl;
            testPassed = false;
        }
    };

    check("pi", pi, 3.141592653589);
    check("eps0", eps0, 8.8541878176e-12);
    check("mu0", mu0, 4.0 * pi * 1e-7);
    check("c0", c0, 2.997924580003e8);
    check("eta0", eta0, 3.767303134622e2);
    check("radtodeg", radtodeg, 180.0 / pi);
    check("degtorad", degtorad, pi / 180.0);

    if (prd_none != 1 || prd_2d != 2) {
        std::cout << "Integer constants test failed." << std::endl;
        testPassed = false;
    }

    if (testPassed) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cout << "Some tests failed. Please check the output." << std::endl;
    }
}

int main() {
    testConstants();
    return 0;
}