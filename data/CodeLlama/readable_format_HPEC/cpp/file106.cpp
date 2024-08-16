#include <iostream>
#include <omp.h>

int main() {
    int var[100];

    // Initialize the array
    for (int i = 0; i < 100; ++i) {
        var[i] = 1;
    }

    // OpenMP target region with map(tofrom:var) device(0)
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP parallel for with ordered directive
        #pragma omp parallel for ordered
        for (int i = 1; i < 100; ++i) { // Note: i starts from 1 to match Fortran's 2:100
            #pragma omp ordered
            var[i] = var[i-1] + 1;
        }
    }

    // Check for data races
    for (int i = 0; i < 100; ++i) {
        if (var[i] != i + 1) { // Adjusted for 0-based indexing
            std::cout << "Data Race Present" << std::endl;
        }
    }

    return 0;
}
