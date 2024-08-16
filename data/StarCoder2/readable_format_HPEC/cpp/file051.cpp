#include <iostream>
#include <omp.h>

int main() {
    const int m = 1;
    const int n = 4;
    float b[4] = {0}; // Initialize all elements to 0

    // OpenMP SIMD directive with safelen(2)
    #pragma omp simd safelen(2)
    for (int i = m; i < n; ++i) {
        b[i] = b[i - m] - 1.0f;
    }

    // Print the third element (index 2 in C++)
    std::cout << b[2] << std::endl;

    return 0;
}
