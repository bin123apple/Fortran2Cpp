#include <iostream>
#include <omp.h>

int main() {
    int x;
    #pragma omp parallel
    {
        foo();
    }
    std::cout << "x = " << x << std::endl;
    return 0;
}

void foo() {
    int i;
    #pragma omp parallel for private(i) lastprivate(x)
    for (int i = 1; i <= 100; i++) {
        x = i;
    }
}
