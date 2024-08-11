#include <iostream>
#include <cstddef>

// Declare the test1 namespace to encapsulate the translated Fortran module functions
namespace test1 {
    // Translated subroutine sub1 from Fortran to C++
    extern "C" void sub1(void* argv) {
        // Intentionally left empty to match the original Fortran example
    }

    // Translated subroutine sub2 from Fortran to C++
    void sub2() {
        void* argv = nullptr;
        char s = '\0';
        sub1(&argv); // Call sub1 within sub2
    }
}

// Test function for sub1
void test_sub1() {
    void* argv = nullptr;
    test1::sub1(&argv); // Call sub1 directly
    std::cout << "sub1 called successfully." << std::endl;
}

// Test function for sub2
void test_sub2() {
    test1::sub2(); // Call sub2 which internally calls sub1
    std::cout << "sub2 called successfully." << std::endl;
}

// Main function to run tests
int main() {
    test_sub1(); // Test the sub1 function
    test_sub2(); // Test the sub2 function
    return 0;
}