#include <iostream>
#include <cmath>

// Namespace to encapsulate the functionality
namespace modphonon {
    // Simple function to calculate the square of a number
    double square(double x) {
        return x * x;
    }
}

// Simple manual test function for the `square` function
void testSquareFunction() {
    using modphonon::square;

    double testValue1 = 2.0;
    double expected1 = 4.0;
    double result1 = square(testValue1);

    if (std::abs(result1 - expected1) < 0.001) {
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed: Expected " << expected1 << ", got " << result1 << std::endl;
    }

    double testValue2 = -3.0;
    double expected2 = 9.0;
    double result2 = square(testValue2);

    if (std::abs(result2 - expected2) < 0.001) {
        std::cout << "Test 2 passed." << std::endl;
    } else {
        std::cout << "Test 2 failed: Expected " << expected2 << ", got " << result2 << std::endl;
    }
}

int main() {
    testSquareFunction();

    return 0;
}