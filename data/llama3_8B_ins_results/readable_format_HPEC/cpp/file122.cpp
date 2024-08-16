#include <iostream>
#include <omp.h>

int main() {
    int var[16] = {0};

    #pragma omp target teams distribute parallel do
    for (int i = 1; i <= 20; i++) {
        #pragma omp simd
        for (int j = 1; j <= 16; j++) {
            var[j-1] += 1;
        }
    }

    std::cout << var[15] << std::endl;

    return 0;
}
