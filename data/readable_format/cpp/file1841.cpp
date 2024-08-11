#include <cstdlib> // For exit() and EXIT_SUCCESS, EXIT_FAILURE
#include <iostream> // For std::cout

// Declaration of function S() before use
int S();

int main() {
    if (S() == 0) {
        std::cout << "S() executed with expected behavior." << std::endl;
    } else {
        std::cout << "S() did not execute as expected." << std::endl;
    }

    // Simulate the STOP 1 behavior with a return value
    return 1; // This would be the place to simulate STOP 1
}

// Definition of subroutine S
int S() {
    // Instead of exiting, return a value to simulate STOP 0
    return 0;
}