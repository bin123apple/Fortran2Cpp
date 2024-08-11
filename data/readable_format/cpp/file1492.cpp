#include <iostream>

// Declaration and definition of FooFixed class
class FooFixed {
public:
    static void bar12(int& a) {
        a = 12;
    }
};

// A simple function to test FooFixed::bar12
void test_bar12() {
    int a = 0;
    FooFixed::bar12(a);
    if (a == 12) {
        std::cout << "Test passed: a = " << a << std::endl;
    } else {
        std::cerr << "Test failed: a = " << a << std::endl;
        exit(1); // Exit with an error status
    }
}

// Main function acting as an entry point and invoking the test
int main() {
    test_bar12(); // Run our simple test
    return 0; // Indicate successful execution
}