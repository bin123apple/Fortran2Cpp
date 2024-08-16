#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    int i, j;

    for (i = 0; i < 8; ++i) {
        var[i] = 0;
    }

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

    std::cout << var[7] << std::endl; // Note: C++ arrays are 0-indexed, so var[7] corresponds to var(8) in Fortran

    return 0;
}
