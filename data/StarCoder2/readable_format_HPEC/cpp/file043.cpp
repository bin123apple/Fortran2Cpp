#include <iostream>
#include <omp.h>

int main() {
    int var[16];

    for (int i = 0; i < 16; ++i) {
        var[i] = 0;
    }

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for reduction(+:var[:16])
        for (int i = 0; i < 20; ++i) {
            #pragma omp simd
            for (int j = 0; j < 16; ++j) {
                var[j] = var[j] + 1;
            }
        }
    }

    for (int i = 0; i < 16; ++i) {
        if (var[i]!= 20) {
            std::cout << var[i] << " " << i << std::endl;
        }
    }

    return 0;
}
