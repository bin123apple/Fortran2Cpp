#include <iostream>

// Declaration of the clawloop function
void clawloop();

int main() {
    // Call the clawloop function to simulate a "test" run
    clawloop();
    // Additional "tests" or calls to clawloop can go here, if needed.

    return 0;
}

// Definition of the clawloop function
void clawloop() {
    int i, j, k;
    int iend = 2;
    int jend = 4;
    int kend = 2;

    for (i = 0; i <= iend; ++i) {
        for (j = 0; j <= jend; ++j) {
            for (k = 0; k <= kend; ++k) {
                if (i == 0) {
                    std::cout << "First iteration of i " << i << "/" << j << "/" << k << std::endl;
                }
                std::cout << "First loop body: " << i << "/" << j << "/" << k << std::endl;
                if (j >= 2) {
                    std::cout << "Second loop body: " << i << "/" << j << "/" << k << std::endl;
                }
            }
        }
    }
}