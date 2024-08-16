#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int i;

    #pragma omp target teams distribute device(0)
    {
        #pragma omp atomic update
        for (i = 1; i <= 100; i++) {
            var++;
        }
    }

    std::cout << var << std::endl;

    return 0;
}
