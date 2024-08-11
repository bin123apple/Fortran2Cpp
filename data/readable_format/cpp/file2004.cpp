#include <iostream>
#include <functional>

// Namespace equivalent to the Fortran module 'm'
namespace m {
    using func_type = std::function<float(float)>; // Type alias for the function

    // The subroutine 'sub' equivalent
    void sub(func_type a) {
        std::cout << a(4.0f) << std::endl; // Calling the passed function with 4.0 as argument
    }
}

// Test function to be passed to 'sub'
float foo(float x) {
    return x * 2.0f; // Example functionality: simply doubles the input
}

// Simple test mechanism to verify 'foo' functionality
void testFoo() {
    float expected = 8.0f;
    float result = foo(4.0f);

    if (result == expected) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    // Use the 'sub' function with 'foo' as argument
    m::sub(foo);

    // Run a simple test to verify 'foo' works as expected
    testFoo();

    return 0;
}