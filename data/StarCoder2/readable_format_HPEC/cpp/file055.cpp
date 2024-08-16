#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int** a = new int*[len];

    // Allocate memory for the 2D array
    for (int i = 0; i < len; ++i) {
        a[i] = new int[len];
    }

    // Initialize array elements to 0
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = 0;
        }
    }

    // Parallel loop to increment array elements
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] += 1;
        }
    }

    // Deallocate memory for the 2D array
    for (int i = 0; i < len; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
