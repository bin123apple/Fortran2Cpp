#include <iostream>
#include <cassert>

// Class definition
class t {
public:
    int dummy;
    t() : dummy(10) {}  // Constructor initializes 'dummy' to 10
    int getDummy() const { return dummy; }  // Getter for 'dummy'
};

// Test function for class t
void test_t_class() {
    t myVar;
    assert(myVar.getDummy() == 10);  // Simple test to check initialization
    std::cout << "Test passed: dummy == 10" << std::endl;
}

// Main function - entry point of the program
int main() {
    test_t_class();  // Run our test
    std::cout << "All tests passed." << std::endl;
    return 0;
}