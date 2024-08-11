#include <iostream>

int factorial(int number);

void testFactorial() {
    struct TestCase {
        int input;
        int expected;
    };

    TestCase testCases[] = {
        {1, 1},
        {2, 2},
        {3, 6},
        {4, 24},
        {5, 120}
    };

    bool allTestsPassed = true;
    for (const auto& testCase : testCases) {
        int result = factorial(testCase.input);
        if (result != testCase.expected) {
            std::cout << "Test failed for input " << testCase.input
                      << ". Expected " << testCase.expected << " but got " << result << "."
                      << std::endl;
        } else {
            std::cout << "Test passed for input " << testCase.input << "."
                      << std::endl;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int factorial(int number) {
    int result = 1;
    for (int i = 1; i <= number; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    testFactorial();
    return 0;
}