#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int i;

    #pragma omp target teams distribute parallel do map(tofrom:var) device(0)
    for (i = 1; i <= 100; i++) {
        #pragma omp critical(addlock)
        var++;
        #pragma omp end critical(addlock)
    }
    #pragma omp end teams distribute parallel do
    #pragma omp end target

    std::cout << var << std::endl;
    return 0;
}
