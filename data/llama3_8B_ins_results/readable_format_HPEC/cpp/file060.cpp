#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int i;

    #pragma omp target teams distribute parallel do reduction(+:var)
    for (i = 1; i <= 200; i++) {
        if (var < 101) {
            var++;
        }
    }
    #pragma omp end teams distribute parallel do
    #pragma omp end target

    std::cout << "Final value of var: " << var << std::endl;

    return 0;
}
