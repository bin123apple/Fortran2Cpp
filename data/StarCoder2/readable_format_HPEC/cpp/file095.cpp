#include <iostream>
#include <omp.h>

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
    int x = 0;
    int y = 2;

    #pragma omp task depend(inout: x) shared(x)
    {
        x = x + 1; // 1st Child Task
    }

    #pragma omp task shared(y)
    {
        y = y - 1; // 2nd child task
    }

    #pragma omp task depend(in: x) if(false) // 1st taskwait equivalent
    {
        // Intentionally left empty
    }

    std::cout << "x=" << x << std::endl;

    #pragma omp taskwait // 2nd taskwait equivalent
    {
        // Intentionally left empty
    }

    std::cout << "y=" << y << std::endl;
}
