#include <iostream>
#include <omp.h>

int main() {
    int lck = 0;
    int var = 0;
    int i;

    #pragma omp target teams distribute parallel do
    for (i = 1; i <= 100; i++) {
        #pragma omp critical
        {
            var++;
        }
    }

    std::cout << "Final value of var: " << var << std::endl;

    return 0;
}
