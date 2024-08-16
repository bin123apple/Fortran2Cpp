#include <iostream>
#include <omp.h>

int main() {
    int m = 2;
    int n = 4;
    float b[4];

    // Initialize b for demonstration purposes
    for (int i = 0; i < 4; ++i) {
        b[i] = static_cast<float>(i + 1); // Just for demonstration; adjust as needed
    }

    #pragma omp simd safelen(2)
    for (int i = m; i < n; ++i) {
        b[i] = b[i - m] - 1.0f;
    }

    std::cout << b[2] << std::endl; // Note: C++ arrays are 0-indexed, so b[2] corresponds to b(3) in Fortran

    return 0;
}
