#include <iostream>
#include <omp.h>

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
    std::cout << "x = " << x << std::endl;
}
