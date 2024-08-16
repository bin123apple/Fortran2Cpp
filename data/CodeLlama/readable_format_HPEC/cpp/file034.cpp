#include <iostream>
#include <omp.h>

// Forward declaration of foo
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
    x = x + 1; // 1st Child Task
    #pragma omp end task

    #pragma omp task shared(y)
    y = y - 1; // 2nd child task
    #pragma omp end task

    #pragma omp taskwait depend(in: x) // 1st taskwait

    std::cout << "x=" << x << std::endl;

    #pragma omp taskwait // 2nd taskwait

    std::cout << "y=" << y << std::endl;
}
