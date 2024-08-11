#include <iostream>

// Global array for demonstration
int b[10];

// Function declarations
void pr43337();
void foo(int* b);
void bar(int* b);

void pr43337() {
    foo(b);
    bar(b);
}

void foo(int* b) {
    for (int a = 0; a < 10; ++a) {
        b[a] = 1;
    }
}

void bar(int* b) {
    for (int a = 0; a < 10; ++a) {
        b[a] = 1;
    }
}

// Simple test function to verify the functionality
void testPr43337() {
    bool testPassed = true;

    // Call the function to test
    pr43337();

    // Check if all elements of the array are set to 1
    for (int i = 0; i < 10; ++i) {
        if (b[i] != 1) {
            testPassed = false;
            std::cout << "Test failed at index " << i << " with value " << b[i] << std::endl;
        }
    }

    if (testPassed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    // Run the test
    testPr43337();
    return 0;
}