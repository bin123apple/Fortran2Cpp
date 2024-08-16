#include <iostream>
#include <omp.h>

int main() {
    int var[16];

    // Initialize array elements to 0
    for (int i = 0; i < 16; ++i) {
        var[i] = 0;
    }

    // OpenMP target directive to specify the target device
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams distribute parallel for directive
        #pragma omp teams distribute parallel for
        for (int i = 0; i < 20; ++i) {
            // OpenMP simd directive
            #pragma omp simd
            for (int j = 0; j < 16; ++j) {
                var[j] = var[j] + 1;
            }
        }
    }

    // Print the last element of the array
    std::cout << var[15] << std::endl;

    return 0;
}
