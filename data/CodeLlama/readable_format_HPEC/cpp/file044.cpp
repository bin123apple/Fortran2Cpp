#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<double> b(8, 0);
    std::vector<double> c(8, 2);
    std::vector<double> temp(8, 0);
    double a = 2;
    double val = 0;

    // Initialize arrays
    for (int i = 0; i < 8; ++i) {
        b[i] = 0;
        c[i] = 2;
        temp[i] = 0;
    }

    // OpenMP target region with map clauses
    #pragma omp target map(tofrom:b[0:8]) map(to:c[0:8], temp[0:8], a) device(0)
    {
        // OpenMP parallel region
        #pragma omp parallel
        {
            // Parallel loop 1
            #pragma omp for
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < 8; ++j) {
                    temp[j] = b[j] + c[j];
                }
            }

            // Parallel loop 2
            #pragma omp for
            for (int i = 0; i < 100; ++i) {
                for (int j = 7; j >= 0; --j) { // Adjusted for 0-based indexing
                    b[j] = temp[j] * a;
                }
            }
        }
    }

    // Serial loop
    for (int i = 0; i < 100; ++i) {
        val = val + 2;
        val = val * 2;
    }

    // Check results
    for (int i = 0; i < 8; ++i) {
        if (val != b[i]) {
            std::cout << b[i] << ", " << val << std::endl;
        }
    }

    return 0;
}
