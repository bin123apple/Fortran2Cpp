#include <iostream>
#include <stdexcept>

// Function to be tested
double doubleNumber(const double x) {
    return x * 2.0;
}

// Simple assert function for the test
void assertEqual(double expected, double actual, const std::string& testName = "") {
    if (expected != actual) {
        std::cerr << "Test Failed: " << testName << " Expected " << expected << ", but got " << actual << std::endl;
    } else {
        std::cout << "Test Passed: " << testName << std::endl;
    }
}

int main() {
    // Conduct the test
    assertEqual(10.0, doubleNumber(5.0), "DoubleNumber Test");
    return 0;
}