#include <iostream>
#include <cassert>

extern "C" {
    // This simulates the Fortran function ffunc(j) with C linkage
    int ffunc(int j) {
        return -17 * j;
    }
}

// Test function to validate the functionality of ffunc
void test_ffunc() {
    // Test 1
    assert(ffunc(13) == -17 * 13);
    std::cout << "C++ Test 1 passed." << std::endl;

    // Test 2
    assert(ffunc(21) == -17 * 21);
    std::cout << "C++ Test 2 passed." << std::endl;
}

int main() {
    // Run tests to verify the functionality
    test_ffunc();
    return 0;
}