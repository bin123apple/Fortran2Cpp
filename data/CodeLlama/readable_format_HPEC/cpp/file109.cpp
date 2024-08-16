#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams num_teams(1)
    {
        #pragma omp distribute parallel for
        for (int i = 1; i <= 100; ++i) {
            var = var + 1;
        }
    }

    std::cout << var << std::endl;

    return 0;
}
