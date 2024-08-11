#include <iostream>

// Functions to be tested
int f() {
    return 1;
}

int rf() {
    return 1;
}

// Test function declarations
void test_f();
void test_rf();

int main() {
    test_f(); // Test the f() function
    test_rf(); // Test the rf() function
    return 0;
}

// Test implementations
void test_f() {
    if (f() == 1) {
        std::cout << "PASS: f() returned 1" << std::endl;
    } else {
        std::cout << "FAIL: f() did not return 1" << std::endl;
    }
}

void test_rf() {
    if (rf() == 1) {
        std::cout << "PASS: rf() returned 1" << std::endl;
    } else {
        std::cout << "FAIL: rf() did not return 1" << std::endl;
    }
}