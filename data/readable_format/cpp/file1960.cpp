#include <iostream>
#include <cassert>

void test(int block[], int array[]) {
    for (int i = array[0] - 1; i <= array[1] - 1; i += 2) {
        for (int j = array[0] - 1; j <= array[1] - 1; j += 3) {
            block[i] = j + 1; // Adjust for 0-based indexing
        }
    }
}

int main() {
    int block[9] = {0}; // Initialize all to 0 for a fair comparison
    int array[2] = {1, 9}; // Test range

    test(block, array);

    // Verify the output matches the Fortran version
    for (int i = 0; i < 9; ++i) {
        std::cout << "block[" << i << "] = " << block[i] << std::endl;
    }

    return 0;
}