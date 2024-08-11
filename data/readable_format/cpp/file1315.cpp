#include <iostream>
#include <cstdlib> // For exit()
#include <cassert> // For assert()

int main() {
    // Adjust the array to match Fortran's column-major order
    int array[2][3] = {{11, 12, 13}, {21, 22, 23}};

    // Output to mimic the Fortran program's output for manual "unit testing"
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "array(" << i+1 << ", " << (j-1) << ") = " << array[i][j] << std::endl;
        }
    }

    // Assertions to verify the initialization (Optional, as we're manually checking)
    assert(array[0][0] == 11);
    assert(array[0][1] == 12);
    assert(array[0][2] == 13);
    assert(array[1][0] == 21);
    assert(array[1][1] == 22);
    assert(array[1][2] == 23);

    std::cout << "All tests passed." << std::endl;

    return 0; // Successful execution
}