#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    int i, j;

    // Initialize the array
    for (i = 0; i < 8; ++i) {
        var[i] = 0;
    }

    // OpenMP target region with map(tofrom:var) device(0)
    #pragma omp target map(tofrom:var) device(0)
    {
        // OpenMP teams num_teams(1) thread_limit(1048)
        #pragma omp teams num_teams(1) thread_limit(1048)
        {
            // OpenMP distribute parallel for reduction(+:var)
            #pragma omp distribute parallel for reduction(+:var[:8])
            for (i = 0; i < 20; ++i) {
                // OpenMP simd
                #pragma omp simd
                for (j = 0; j < 8; ++j) {
                    var[j] = var[j] + 1;
                }
            }
        }
    }

    // Check the results
    for (i = 0; i < 8; ++i) {
        if (var[i] != 20) {
            std::cout << var[i] << std::endl;
        }
    }

    return 0;
}
