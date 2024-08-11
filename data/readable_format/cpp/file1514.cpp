#include <iostream>
#include <string>

// Function to test
int square(int x) {
    return x * x;
}

// Simple test function without using Google Test or any external libraries
void testSquare() {
    int input = 4;
    int expected = 16;
    int result = square(input);

    if (result == expected) {
        std::cout << "Test passed: square(" << input << ") == " << expected << std::endl;
    } else {
        std::cout << "Test failed: square(" << input << ") != " << expected << ", got " << result << std::endl;
    }
}

// Main function
int main() {
    // Call the test function
    testSquare();

    return 0;
}