#include <iostream>
#include <cmath>
#include <cassert>

const double U_PI = 3.141592653589793;

void test_U_PI() {
    // Testing U_PI against the expected value within a small tolerance
    const double tolerance = 1.0E-15;
    assert(std::abs(U_PI - 3.141592653589793) < tolerance && "U_PI value does not match the expected output.");
    std::cout << "C++ Test passed." << std::endl;
}

int main() {
    // Demonstrating U_PI value
    std::cout << "Demonstrating U_PI value: " << U_PI << std::endl;

    // Run the unit test
    test_U_PI();

    return 0;
}