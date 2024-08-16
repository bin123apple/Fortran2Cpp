#include <iostream>
#include <omp.h>

int main() {
    int var[100];

    // Initialize the array
    for (int i = 0; i < 100; ++i) {
        var[i] = 1;
    }

    // OpenMP pragma for targeting GPU (assuming 0-based indexing)
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams distribute parallel for directive with simd
        #pragma omp teams distribute parallel for simd safelen(16)
        for (int i = 17; i < 100; ++i) {
            var[i] = var[i - 16] + 1;
        }
    }

    // Print the value of var[97] (equivalent to Fortran's 98 due to 0-based indexing)
    std::cout << var[97] << std::endl;

    return 0;
}
