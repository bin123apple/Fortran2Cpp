#include <iostream>
#include <omp.h>

// Forward declaration of foo to be used in the parallel region
void foo();

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        foo();
    }
    return 0;
}

void foo() {
    int x, y;
    x = 0;
    y = 2;

    #pragma omp task depend(inout: x) shared(x)
    x = x + 1; // 1st Child Task
    #pragma omp end task

    #pragma omp task shared(y)
    y = y - x; // 2nd child task
    #pragma omp end task

    #pragma omp taskwait depend(in: x) // 1st taskwait

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    #pragma omp taskwait // 2nd taskwait
}
