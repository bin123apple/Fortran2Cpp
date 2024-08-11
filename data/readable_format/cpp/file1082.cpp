#include <iostream>

// Declaration of the function to be tested
void clawloop();

// A simple manual test function
void testClawloop() {
    // Correctly concatenate the string literals for multi-line output
    std::cout << "Running testClawloop..." << std::endl;
    clawloop();
    std::cout << "Test completed. Check the output manually." << std::endl;
}

int main() {
    // Call the test function
    testClawloop();
    return 0;
}

// Definition of the function under test
void clawloop() {
    int i, j, k;
    int iend = 2;
    int jend = 4;
    int kend = 2;

    for (i = 0; i <= iend; ++i) {
        if (i == 0) {
            std::cout << "First iteration of i " << i << std::endl;
        }
        for (j = 0; j <= jend; ++j) {
            for (k = 0; k <= kend; ++k) {
                std::cout << "First loop body: " << i << '/' << j << '/' << k << std::endl;
            }
        }

        for (j = 2; j <= jend; ++j) {
            for (k = 0; k <= kend; ++k) {
                std::cout << "Second loop body: " << i << '/' << j << '/' << k << std::endl;
            }
        }

        for (j = 0; j <= jend; ++j) {
            std::cout << "ALONE J LOOP" << std::endl;
        }
    }
}