#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int i;

    #pragma omp target teams distribute parallel do map(tofrom:var) device(0)
    {
        for (i = 1; i <= 200; i++) {
            #pragma omp critical
            {
                var++;
            }
        }
    }

    std::cout << var << std::endl;

    return 0;
}
