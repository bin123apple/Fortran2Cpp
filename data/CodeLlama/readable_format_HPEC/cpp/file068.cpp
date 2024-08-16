#include <iostream>
#include <omp.h>

int main() {
    const int size = 100;
    int a[size][size];
    int errors = 0;

    // Initialize the array
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = 0;
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    // Verify the results
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (a[i][j] != 1) {
                std::cout << "Error at: " << i << ", " << j << ", " << a[i][j] << std::endl;
                errors++;
            }
        }
    }

    if (errors == 0) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cout << "Number of errors: " << errors << std::endl;
    }

    return 0;
}
