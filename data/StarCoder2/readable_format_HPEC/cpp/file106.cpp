#include <iostream>
#include <omp.h>

int main() {
    int var[100];

    // Initialize array
    for (int i = 0; i < 100; ++i) {
        var[i] = 1;
    }

    // OpenMP target directive with device(0)
    #pragma omp target map(tofrom:var[0:100]) device(0)
    {
        // OpenMP parallel for directive with ordered
        #pragma omp parallel for ordered
        for (int i = 1; i < 100; ++i) {
            #pragma omp ordered
            var[i] = var[i - 1] + 1;
        }
    }

    // Verification loop
    for (int i = 0; i < 100; ++i) {
        if (var[i]!= i + 1) {
            std::cout << "Data Race Present" << std::endl;
        }
    }

    return 0;
}
