#include <iostream>
#include <omp.h>

int main() {
    const int m = 2;
    const int n = 4;
    float b[4];

    // Initialize the array b
    b[0] = 0.0f; // Assuming b[0] is used in the original Fortran code
    b[1] = 1.0f; // Assuming b[1] is used in the original Fortran code
    b[2] = 2.0f; // Assuming b[2] is used in the original Fortran code
    b[3] = 3.0f; // Assuming b[3] is used in the original Fortran code

    // OpenMP simd directive with safelen(2)
    #pragma omp simd safelen(2)
    for (int i = m + 1; i <= n; ++i) {
        b[i] = b[i - m] - 1.0f;
    }

    // Print the value of b[3]
    std::cout << b[3] << std::endl;

    return 0;
}
