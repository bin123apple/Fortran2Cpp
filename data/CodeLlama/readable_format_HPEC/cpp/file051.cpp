#include <iostream>
#include <omp.h>

int main() {
    const int m = 1;
    const int n = 4;
    float b[4];

    // Initialize the array
    b[0] = 0.0f; // Assuming b[0] was initialized somewhere else in your code
    b[1] = 1.0f;
    b[2] = 2.0f;
    b[3] = 3.0f;

    // OpenMP SIMD directive for vectorization
    #pragma omp simd safelen(2)
    for (int i = m + 1; i <= n; ++i) {
        b[i - 1] = b[i - m - 1] - 1.0f; // Adjusted for 0-based indexing
    }

    // Print the value of b[3] (equivalent to b(3) in Fortran)
    std::cout << b[3 - 1] << std::endl; // Adjusted for 0-based indexing

    return 0;
}
