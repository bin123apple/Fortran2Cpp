#include <iostream>
#include <omp.h>

// Assuming 'var' is a global array or passed as an argument
int var[16];

int main() {
    // Initialize the array
    for (int i = 0; i < 16; ++i) {
        var[i] = 0;
    }

    // OpenMP pragmas for targeting GPU (device 0)
    #pragma omp target map(tofrom:var) device(0)
    {
        // Teams distribute parallel for
        #pragma omp teams distribute parallel for
        for (int i = 0; i < 20; ++i) {
            // Simd directive
            #pragma omp simd
            for (int j = 0; j < 16; ++j) {
                var[j] = var[j] + 1;
            }
        }
    }

    // Print the value of the 16th element (0-based indexing in C++)
    std::cout << var[15] << std::endl;

    return 0;
}
