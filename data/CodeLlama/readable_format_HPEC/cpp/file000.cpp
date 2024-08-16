#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int** a = new int*[len];
    
    // Allocate and initialize the 2D array
    for (int i = 0; i < len; ++i) {
        a[i] = new int[len];
        for (int j = 0; j < len; ++j) {
            a[i][j] = 0; // Initialize to 0, or any value as needed
        }
    }

    // Parallel region with collapse(2)
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    // Clean up the dynamically allocated memory
    for (int i = 0; i < len; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
