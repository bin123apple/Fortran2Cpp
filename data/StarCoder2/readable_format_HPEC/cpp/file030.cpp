#include <iostream>
#include <omp.h>

// Assuming DRB158 functionalities are translated or included here

int main() {
    int x[64];
    int y[64];
    int a;

    // Initialization of x and y arrays
    for (int i = 0; i < 64; ++i) {
        x[i] = 0;
        y[i] = 3;
    }

    a = 5;

    // OpenMP target directive with data mapping
    #pragma omp target map(to:y[0:64],a) map(tofrom:x[0:64]) device(0)
    {
        // Parallel loop with tasks
        #pragma omp parallel for
        for (int i = 0; i < 64; ++i) {
            // Task 1: x[i] = a*x[i]
            #pragma omp task depend(inout:x[i])
            {
                x[i] = a * x[i];
            }

            // Task 2: x[i] = x[i] + y[i]
            #pragma omp task depend(inout:x[i])
            {
                x[i] = x[i] + y[i];
            }
        }
    }

    // Verification of results
    for (int i = 0; i < 64; ++i) {
        if (x[i]!= 3) {
            std::cout << x[i] << std::endl;
        }
    }

    // Wait for all tasks to complete
    #pragma omp taskwait

    return 0;
}
