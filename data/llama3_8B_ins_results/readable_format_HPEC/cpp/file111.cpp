#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    int i, j;

    // Initialize var array
    for (i = 0; i < 8; i++) {
        var[i] = 0;
    }

    // OpenMP target region
    #pragma omp target teams distribute parallel do reduction(+:var[0:7])
    for (i = 0; i < 20; i++) {
        #pragma omp simd
        for (j = 0; j < 8; j++) {
            var[j]++;
        }
    }

    // OpenMP end target region

    // Check if var array is correct
    for (i = 0; i < 8; i++) {
        if (var[i]!= 20) {
            std::cout << var[i] << std::endl;
        }
    }

    return 0;
}
