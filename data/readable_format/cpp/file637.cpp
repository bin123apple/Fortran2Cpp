#include <iostream>
#include <cassert>

// Mimicking the Fortran module with a namespace
namespace m_dom_debug {
    bool dom_debug = false; // Equivalent to the Fortran logical type
}

// Function prototypes for tests
void test_initial_value();
void test_modification();

int main() {
    // Run tests
    test_initial_value();
    test_modification();
    
    std::cout << "All tests passed." << std::endl;
    return 0;
}

void test_initial_value() {
    assert(m_dom_debug::dom_debug == false);
    std::cout << "Test 1 Passed: dom_debug is initially false." << std::endl;
}

void test_modification() {
    m_dom_debug::dom_debug = true;
    assert(m_dom_debug::dom_debug == true);
    std::cout << "Test 2 Passed: dom_debug can be set to true." << std::endl;
}