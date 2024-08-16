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
    #pragma omp target teams distribute device(0)
    {
        // OpenMP parallel region
        #pragma omp parallel
        {
            // OpenMP ordered region
            #pragma omp for ordered
            for (i = 2; i < 100; i++) {
                var[i] = var[i-1] + 1;
            }
        }
    }

    // Check for data races
    for (i = 1; i <= 100; i++) {
        if (var[i]!= i) {
            std::cout << "Data Race Present" << std::endl;
        }
    }

    return 0;
}
