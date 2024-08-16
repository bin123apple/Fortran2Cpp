#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int i;

    #pragma omp target teams distribute parallel do
    for (int i = 1; i <= 100; i++) {
        var++;
    }

    #pragma omp end target

    std::cout << var << std::endl;

    return 0;
}
