#include <iostream>
#include <omp.h>

// Assuming the existence of a module DRB158 in Fortran, 
// we need to define equivalent variables and functions in C++.
// For simplicity, we'll define them globally here.
double x[64];
double y[64];
double a;

int main() {
    // Initialize arrays x and y, and variable a
    for (int i = 0; i < 64; ++i) {
        x[i] = 0;
        y[i] = 3;
    }
    a = 5;

    // OpenMP target region with map clauses
    #pragma omp target map(to:y[0:64], a) map(tofrom:x[0:64]) device(0)
    {
        // Parallel loop with tasks
        #pragma omp parallel for
        for (int i = 0; i < 64; ++i) {
            // Task 1: x[i] = a * x[i]
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

    // Check results and print non-zero values of x
    for (int i = 0; i < 64; ++i) {
        if (x[i] != 3) {
            std::cout << x[i] << std::endl;
        }
    }

    // Wait for all tasks to complete
    #pragma omp taskwait

    return 0;
}