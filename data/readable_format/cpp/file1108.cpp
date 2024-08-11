#include <iostream>
#include <cassert>

// Define a namespace to encapsulate the functionality, similar to the Fortran module
namespace mod {
    int i = 42; // Global variable within namespace

    // Function to print the value of 'i'
    void print_i() {
        std::cout << i << std::endl;
    }
}

// Function to test the value of 'i' in the mod namespace
void test_mod_i() {
    int expected_value = 42;
    assert(mod::i == expected_value); // Assert that the value of 'i' is as expected
    std::cout << "Test passed: mod::i is " << mod::i << std::endl;
}

int main() {
    // Call the function to print 'i'
    mod::print_i();

    // Run the test
    test_mod_i();

    return 0;
}