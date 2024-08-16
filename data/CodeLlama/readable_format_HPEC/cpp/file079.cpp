#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    int i, j;

    // Initialize the array
    for (i = 0; i < 8; ++i) {
        var[i] = 0;
    }

    // OpenMP pragmas for parallel processing
    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams num_teams(1) thread_limit(1048)
        {
            #pragma omp distribute parallel for
            for (i = 0; i < 20; ++i) {
                #pragma omp simd
                for (j = 0; j < 8; ++j) {
                    var[j] = var[j] + 1;
                }
            }
        }
    }

    // Print the last element of the array
    std::cout << var[7] << std::endl;

    return 0;
}
