#include <iostream>
#include <omp.h>

int main() {
    int var = 0; // Initialize var to 0

    // OpenMP target directive with map(tofrom:var) and device(0)
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams distribute parallel for directive
        #pragma omp teams distribute parallel for
        for (int i = 1; i <= 100; ++i) {
            var += 1;
        }
    }

    // Print the result
    std::cout << var << std::endl;

    return 0;
}
