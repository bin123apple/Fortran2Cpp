#include <iostream>
#include <omp.h>

int main() {
    int x = 0;

    #pragma omp parallel for ordered
    for (int i = 1; i <= 100; ++i) {
        #pragma omp ordered
        x = x + 1;
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
