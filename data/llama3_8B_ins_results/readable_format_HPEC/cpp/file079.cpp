#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    int i, j;

    // Initialize the array
    for (i = 0; i < 8; i++) {
        var[i] = 0;
    }

    // OpenMP target directive
    #pragma omp target teams distribute parallel do
    for (i = 0; i < 20; i++) {
        // SIMD directive
        #pragma omp simd
        for (j = 0; j < 8; j++) {
            var[j]++;
        }
    }

    // Print the result
    std::cout << var[7] << std::endl;

    return 0;
}
