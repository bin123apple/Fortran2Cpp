#include <iostream>
#include <omp.h>

int main() {
    int var[8];
    for (int i = 0; i < 8; i++)
        var[i] = 0;

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams num_teams(1) thread_limit(1048)
    #pragma omp distribute parallel for reduction(+:var)
    for (int i = 0; i < 20; i++) {
        #pragma omp simd
        for (int j = 0; j < 8; j++)
            var[j] += 1;
    }

    for (int i = 0; i < 8; i++) {
        if (var[i] != 20)
            std::cout << var[i] << std::endl;
    }

    return 0;
}
