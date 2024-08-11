#include <iostream>
#include <cmath> // For fabs

// Function declaration
float square(float x);

// A simple test function
void testSquare() {
    float input = 4.0;
    float expected = 16.0;
    float result = square(input);

    if (fabs(result - expected) < 0.001) {
        std::cout << "Test passed: square(" << input << ") = " << result << std::endl;
    } else {
        std::cout << "Test failed: square(" << input << ") = " << result << std::endl;
    }
}

// Main function
int main() {
    // Running the test
    testSquare();
    return 0;
}

// Function definition
float square(float x) {
    return x * x;
}