#include <iostream>
#include <omp.h>

void foo() {
    int x = 0;
    int y = 2;

    #pragma omp parallel
    {
        #pragma omp single
        {
            x = x + 1; // 1st Child Task
        }

        #pragma omp task depend(inout: x) shared(x)
        {
            x = x + 1; // 2nd Child Task
        }

        #pragma omp task depend(in: x) depend(inout: y) shared(x, y)
        {
            y = y - x; // 3rd Child Task
        }

        #pragma omp task depend(in: x) if(false) // 1st taskwait
        {
            // do nothing
        }

        #pragma omp taskwait // 2nd taskwait

        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    }
}

int main() {
    #pragma omp parallel
    {
        foo();
    }

    return 0;
}
