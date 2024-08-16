#include <iostream>
#include <omp.h>

int main() {
    int var[100];

    // Initialize the array
    for (int i = 0; i < 100; ++i) {
        var[i] = 1;
    }

    // OpenMP target directive
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams distribute parallel for directive
        #pragma omp teams distribute parallel for
        for (int i = 1; i < 100; ++i) {
            var[i] = var[i - 1] + 1;
        }
    }

    // Print the last element of the array
    std::cout << var[99] << std::endl;

    return 0;
}
