#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

double pythag_sp(double a, double b) {
    return std::sqrt(a*a + b*b);
}

// A simple struct to hold test data
struct TestData {
    double a;
    double b;
    double expected;
};

// Function to test the pythag_sp function
void test_pythag_sp(const std::vector<TestData>& tests) {
    bool all_tests_passed = true;

    for (const auto& test : tests) {
        double result = pythag_sp(test.a, test.b);
        if (std::fabs(result - test.expected) > 1e-6) { // Using a small threshold for floating point comparison
            std::cout << "Test failed: pythag_sp(" << test.a << ", " << test.b 
                      << ") = " << result << ", expected: " << test.expected << std::endl;
            all_tests_passed = false;
        }
    }

    if (all_tests_passed) {
        std::cout << "All tests passed." << std::endl;
    }
}

int main() {
    // Define a list of tests
    std::vector<TestData> tests = {
        {0.0, 0.0, 0.0},                   // Both sides zero
        {0.0, 3.0, 3.0},                   // One side zero, the other positive
        {3.0, 3.0, std::sqrt(3.0*3.0*2)},  // Both sides positive and equal
        {3.0, 4.0, 5.0},                   // Both sides positive and different
    };

    // Run the tests
    test_pythag_sp(tests);

    return 0;
}