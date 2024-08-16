#include <iostream>
#include <omp.h>

int main() {
    int x = 2;

    #pragma omp task shared(x) mergeable
    x = x + 1;

    #pragma omp end task

    std::cout << "x = " << x << std::endl;

    return 0;
}
