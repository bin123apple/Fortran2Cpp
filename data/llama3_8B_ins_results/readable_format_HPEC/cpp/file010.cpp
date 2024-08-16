#include <iostream>
#include <omp.h>

int main() {
    int var[100];
    int i;

    // Initialize the array
    for (i = 0; i < 100; i++) {
        var[i] = 1;
    }

    // OpenMP parallel region
    #pragma omp target teams distribute parallel do
    for (i = 1; i < 100; i++) {
        var[i] = var[i-1] + 1;
    }

    // Print the result
    std::cout << var[99] << std::endl;

    return 0;
}
