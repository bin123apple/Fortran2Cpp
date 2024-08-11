#include <iostream>
#include <cassert>

// Base class corresponding to Fortran 'type foo'
class foo {
public:
    // Virtual function to allow overriding in derived class
    virtual void bar(int& j) {
        // Base class implementation
        std::cout << "Base bar, j: " << j << std::endl;
    }
    
    // Virtual destructor for proper cleanup of derived classes
    virtual ~foo() {}
};

// Derived class corresponding to Fortran 'type, extends(foo) :: extfoo'
class extfoo : public foo {
public:
    // Override the bar function
    void bar(int& j) override {
        // Derived class implementation
        j += 1; // Example modification to show intent(inout)
        std::cout << "Derived bar, j: " << j << std::endl;
    }
};

// Simple test function to verify functionality
void test() {
    int j_base = 1;
    int j_derived = 1;
    
    foo* basePtr = new foo();
    basePtr->bar(j_base);
    assert(j_base == 1); // Assuming base.bar doesn't change j, it should still be 1
    
    foo* derivedPtr = new extfoo();
    derivedPtr->bar(j_derived);
    assert(j_derived == 2); // Assuming derived.bar increments j, it should now be 2
    
    delete basePtr;
    delete derivedPtr;
    
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test();
    
    return 0;
}