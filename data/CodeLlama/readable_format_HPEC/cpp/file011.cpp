#include <iostream>
#include <omp.h>

// Function prototype
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

    #pragma omp task depend(in: x) depend(inout: y) shared(x, y)
    y = y - x; // 2nd child task
    #pragma omp end task

    #pragma omp task depend(in: x) if(false) // This task will not execute
    #pragma omp end task

    std::cout << "x=" << x << std::endl;

    #pragma omp taskwait // 2nd taskwait

    std::cout << "y=" << y << std::endl;
}
