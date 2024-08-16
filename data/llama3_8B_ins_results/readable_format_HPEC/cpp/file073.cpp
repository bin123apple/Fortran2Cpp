#include <iostream>
#include <omp.h>

int main() {
    int x = 0, i;

    #pragma omp parallel for ordered
    for (i = 1; i <= 100; i++) {
        x++;
    }

    #pragma omp end parallel

    std::cout << "x = " << x << std::endl;

    return 0;
}
