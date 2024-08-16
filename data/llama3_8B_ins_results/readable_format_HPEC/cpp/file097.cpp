#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int i;

    #pragma omp target teams distribute parallel do
    {
        for (int i = 0; i <= 100; i++) {
            #pragma omp atomic
            var += 1;
            #pragma omp atomic
            var -= 2;
        }
    }

    std::cout << var << std::endl;

    return 0;
}
