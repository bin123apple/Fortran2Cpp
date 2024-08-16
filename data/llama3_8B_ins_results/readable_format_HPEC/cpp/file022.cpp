#include <iostream>
#include <omp.h>

int main() {
    int var[100];
    int i;

    // Initialize the array
    for (i = 0; i < 100; i++) {
        var[i] = 1;
    }

    // OpenMP target region
    #pragma omp target teams distribute parallel do simd safelen(16)
    for (i = 16; i < 100; i++) {
        var[i] = var[i-16] + 1;
    }
    #pragma omp end teams distribute parallel do simd

    // End of OpenMP target region

    // Print the result
    std::cout << var[98] << std::endl;

    return 0;
}
