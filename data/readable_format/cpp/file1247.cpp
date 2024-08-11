#include <cmath>
#include <iostream>
#include <cassert>

// Function pointer type that matches the Fortran interface
using SinInterface = float (*)(float);

// Wrapper function to adapt std::sin (which takes and returns double) to our interface
float sinWrapper(float x) {
    return static_cast<float>(std::sin(static_cast<double>(x)));
}

// Function that returns a pointer to a function matching the SinInterface
SinInterface f() {
    return &sinWrapper;
}

void test_sin_function() {
    SinInterface sinFunc = f();

    // Test the sin function for a known value
    float input = 0.5f; // 30 degrees
    float expected = std::sin(static_cast<double>(input));
    float actual = sinFunc(input);
    
    assert(std::abs(expected - actual) < 0.0001);
    std::cout << "Test Passed. Result: " << actual << std::endl;
}

int main() {
    test_sin_function();
    return 0;
}