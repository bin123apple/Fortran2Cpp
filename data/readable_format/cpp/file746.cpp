#include <iostream>
#include <cmath> // For fabs()

// Function to be tested
void bad1(double& d) {
    d = 5.0;
}

// A very simple test "framework"
void test_bad1() {
    double d = 0.0;
    bad1(d);

    if (std::fabs(d - 5.0) < 1e-6) { // Simple floating point comparison
        std::cout << "Test passed: d equals 5.0" << std::endl;
    } else {
        std::cout << "Test failed: d does not equal 5.0" << std::endl;
    }
}

int main() {
    test_bad1(); // Run the test
    return 0;
}