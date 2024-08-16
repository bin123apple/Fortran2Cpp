#include <iostream>
#include <omp.h>

int main() {
    int var[100];

    // Initialize the array
    for (int i = 0; i < 100; ++i) {
        var[i] = 1;
    }

    // OpenMP target directive with map(tofrom:var) and device(0)
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams distribute parallel for simd directive
        #pragma omp teams distribute parallel for simd safelen(16)
        for (int i = 16; i < 100; ++i) {
            var[i] = var[i - 16] + 1;
        }
    }

    // Print the value of var[97] (since C++ arrays are 0-based)
    std::cout << var[97] << std::endl;

    return 0;
}
