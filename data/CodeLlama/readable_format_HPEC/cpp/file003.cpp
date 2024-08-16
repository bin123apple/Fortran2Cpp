#include <iostream>
#include <omp.h>

// Forward declaration of foo to be used in the parallel region
void foo();

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            foo();
        }
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

    #pragma omp task depend(in: x) depend(inout: y) shared(x, y)
    {
        y = y - x; // 2nd child task
    }

    // The condition in the if statement is always false, so the task is effectively not created
    #pragma omp task depend(in: x) if(false)
    {
        // This task is not executed
    }

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    #pragma omp taskwait // 2nd taskwait
}
