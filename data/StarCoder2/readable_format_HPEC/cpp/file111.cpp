#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    int i, j;

    // Initialize array elements to 0
    for (i = 0; i < 8; ++i) {
        var[i] = 0;
    }

    // OpenMP target directive
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams directive with 1 team and thread limit of 1048
        #pragma omp teams num_teams(1) thread_limit(1048)
        {
            // OpenMP distribute parallel for directive with reduction on var
            #pragma omp distribute parallel for reduction(+:var[:8])
            for (i = 0; i < 20; ++i) {
                // OpenMP simd directive
                #pragma omp simd
                for (j = 0; j < 8; ++j) {
                    var[j] = var[j] + 1;
                }
            }
        }
    }

    // Check if any element of var is not equal to 20 and print it
    for (i = 0; i < 8; ++i) {
        if (var[i]!= 20) {
            std::cout << var[i] << std::endl;
        }
    }

    return 0;
}
