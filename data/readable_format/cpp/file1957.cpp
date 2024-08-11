#include <iostream>
#include <omp.h>

int main() {
    const int size = 10;
    int a[size];

    #pragma omp simd
    for(int i = 0; i < size; ++i) {
        a[i] = i + 1; // Adjusted to match Fortran's 1-based indexing
    }

    // Print the array
    for(int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}