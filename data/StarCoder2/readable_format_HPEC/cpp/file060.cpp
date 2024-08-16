#include <omp.h>
#include <iostream>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for reduction(+:var)
        for (int i = 1; i <= 200; ++i) {
            if (var < 101) {
                var += 1;
            }
        }
    }

    return 0;
}
