#include <iostream>
#include <cstdint>

// Definition of the foo namespace and the constant pi
namespace foo {
    const int32_t pi = 3;
}

// A simple function to test the value of pi
void testPi() {
    std::cout << "Testing the value of pi..." << std::endl;
    if (foo::pi == 3) {
        std::cout << "Test passed. pi is 3." << std::endl;
    } else {
        std::cout << "Test failed. pi is not 3." << std::endl;
    }
}

int main() {
    // Printing the value of pi
    std::cout << "The value of pi is: " << foo::pi << std::endl;
    
    // Running the test
    testPi();

    return 0;
}