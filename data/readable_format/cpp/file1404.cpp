#include <iostream>
#include <cmath>

// Function declaration
double specific_anint_r8(double parm);

// Main function to run tests
int main() {
    // Test cases
    struct TestCase {
        double input;
        double expected;
    };

    TestCase tests[] = {
        {1.4, 1.0},
        {1.6, 2.0},
        {-1.4, -1.0},
        {-1.6, -2.0}
    };

    bool allTestsPassed = true;
    for (const auto& test : tests) {
        double result = specific_anint_r8(test.input);
        if (result != test.expected) {
            std::cout << "Test failed: specific_anint_r8(" << test.input << ") = "
                      << result << ", expected " << test.expected << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return allTestsPassed ? 0 : 1;
}

// Function definition
double specific_anint_r8(double parm) {
    return std::round(parm);
}