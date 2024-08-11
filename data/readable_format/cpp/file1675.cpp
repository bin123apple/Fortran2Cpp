#include <iostream>
#include <cmath> // For std::abs

// The function to be tested
double SECOND() {
    return 0.0;
}

// A simple test function
void test_SECOND() {
    double result = SECOND();
    const double epsilon = 1e-7; // Tolerance for floating-point comparison

    if (std::abs(result - 0.0) < epsilon) {
        std::cout << "Test Passed!" << std::endl;
    } else {
        std::cout << "Test Failed! Result was " << result << std::endl;
    }
}

int main() {
    // Run the test
    test_SECOND();

    return 0;
}