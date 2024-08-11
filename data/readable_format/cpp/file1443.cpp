#include <cassert>
#include <iostream>

// Define the class 't' as per the translated version from the Fortran code
class t {
public:
    bool x;

    // Constructor
    t() : x(false) {}

    // Member functions equivalent to Fortran procedures
    int onearg() const {
        return 5;
    }

    int twoarg1(int a) const {
        return 42;
    }

    int twoarg2(float a) const {
        return 123;
    }

    // Overloaded operators
    int operator()(int a) const { // Mimics twoarg1
        return twoarg1(a);
    }

    int operator()(float a) const { // Mimics twoarg2
        return twoarg2(a);
    }

    // Custom assignment operator mimicking assign_proc
    t& operator=(const bool& b) {
        x = !b;
        return *this;
    }
};

int main() {
    t obj;

    // Test the custom assignment operator
    obj = false; // This should set obj.x to true
    assert(obj.x == true);
    std::cout << "Custom assignment operator test passed." << std::endl;

    // Test onearg
    assert(obj.onearg() == 5);
    std::cout << "onearg test passed." << std::endl;

    // Test twoarg1 with an int argument
    assert(obj.twoarg1(10) == 42);
    std::cout << "twoarg1 with int argument test passed." << std::endl;

    // Test twoarg2 with a float argument
    assert(obj.twoarg2(10.5f) == 123);
    std::cout << "twoarg2 with float argument test passed." << std::endl;

    std::cout << "All tests passed." << std::endl;

    return 0;
}