#include <iostream>
#include <omp.h>

// Function prototype
void foo();

int main() {
    #pragma omp parallel
    {
        foo();
    }
    return 0;
}

void foo() {
    int i, x;
    #pragma omp parallel for private(i) lastprivate(x)
    for (i = 1; i <= 100; ++i) {
        x = i;
    }
    #pragma omp critical
    {
        std::cout << "x = " << x << std::endl;
    }
}
