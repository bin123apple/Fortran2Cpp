#include <iostream>

// Assume mainProgram is a function that contains the translated logic
// and returns an integer status code.
int mainProgram(); 

void testMatrixCount() {
    int result = mainProgram();
    if (result == 0) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed with status: " << result << std::endl;
    }
}

int main() {
    testMatrixCount();
    return 0;
}

// Mock implementation of mainProgram for demonstration. Replace with actual logic.
int mainProgram() {
    // Your translated C++ code refactored to be inside this function
    // and return status codes instead of calling 'return 1;' directly.
    return 0; // Example success status
}