#include <iostream>
#include <cassert>

// Declaration of multi_mod1 and multi_mod2 as namespaces
namespace multi_mod1 {
    int a = 5;  // Initialized with example values
}

namespace multi_mod2 {
    int b = 10;  // Initialized with example values
}

int main() {
    // Basic "unit tests"
    std::cout << "Running tests..." << std::endl;

    // Test 1: Check value of a in multi_mod1
    assert(multi_mod1::a == 5);
    std::cout << "Test 1 passed: multi_mod1::a == 5" << std::endl;

    // Test 2: Check value of b in multi_mod2
    assert(multi_mod2::b == 10);
    std::cout << "Test 2 passed: multi_mod2::b == 10" << std::endl;

    std::cout << "All tests passed." << std::endl;

    // Demonstrating original program functionality
    std::cout << "Values from modules: " << multi_mod1::a << " " << multi_mod2::b << std::endl;

    return 0;
}