#include <algorithm> // For std::min
#include <cstdlib>   // For std::abs
#include <iostream>
#include <cassert>   // For assert()

void testMinFunction() {
    int X = 1;
    int result = std::min(X, 4);
    assert(result == 1); // If this assertion fails, the program will terminate.
    std::cout << "Test 1 passed: min function works as expected." << std::endl;
}

void testAbsFunction() {
    int Y = -3;
    int result = std::abs(Y);
    assert(result == 3); // If this assertion fails, the program will terminate.
    std::cout << "Test 2 passed: abs function works as expected." << std::endl;
}

int main() {
    // Execution of the original functionality
    int X = 1;
    int Y = -1;

    Y = std::min(X, 4);
    Y = std::abs(Y);
    std::cout << "Y = " << Y << " after operations." << std::endl;

    // Tests
    testMinFunction();
    testAbsFunction();
    std::cout << "All tests passed." << std::endl;

    return 0;
}