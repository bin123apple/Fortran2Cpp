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

    #pragma omp task shared(y)
    {
        y = y - 1; // 2nd child task
    }

    // The if condition is always true, so the task with the taskwait is not needed
    // #pragma omp task depend(in: x) if(false)
    // {
    //     // This task would wait for the first task to complete, but since the condition is always false, it's effectively a no-op
    // }

    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    // The taskwait directive is not needed as the program ends here
}
