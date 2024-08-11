#include <iostream>
#include <cstdlib> // For std::abort()

// Equivalent of the foo_mod module
class foo {
public:
    foo() : i(0) {} // Constructor to initialize i
    virtual void do_it() {
        i = 1;
        std::cout << "FOO::do_it base version" << std::endl;
    }
    virtual int get_it() {
        return i;
    }
protected:
    int i; // This corresponds to the integer :: i in the Fortran code
};

// Equivalent of the foo2_mod module
class foo2 : public foo {
public:
    foo2() : j(0) {} // Constructor to initialize j
    void do_it() override {
        i = 2;
        j = 3;
    }
    int get_it() override {
        return j;
    }
protected:
    int j; // This corresponds to the integer :: j in the Fortran code
};

// Manual test functions
void testBaseClass() {
    foo af;
    af.do_it(); // Should set i to 1
    if (af.get_it() != 1) {
        std::cerr << "Base class method get_it() failed to return correct value." << std::endl;
        std::abort();
    }
}

void testDerivedClass() {
    foo2 af2;
    af2.do_it(); // Should set i to 2 and j to 3
    // Direct access to 'i' is not allowed since it's protected, but its effect is tested implicitly
    if (af2.get_it() != 3) {
        std::cerr << "Derived class method get_it() failed to return correct value." << std::endl;
        std::abort();
    }
}

int main() {
    testBaseClass();
    testDerivedClass();
    
    std::cout << "All tests passed successfully." << std::endl;
    
    return 0;
}