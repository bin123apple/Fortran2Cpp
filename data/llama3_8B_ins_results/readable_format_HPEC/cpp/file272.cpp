#include <iostream>
#include <omp.h>

int main() {
    int x = 0, y = 2;

    #pragma omp parallel
    {
        #pragma omp single
        {
            foo(x, y);
        }
    }

    return 0;
}

void foo(int& x, int& y) {
    #pragma omp task depend(out: x)
    {
        x += 1; // 1st Child Task
    }

    #pragma omp task
    {
        y -= 1; // 2nd child task
    }

    #pragma omp taskwait depend(in: x) // 1st taskwait
    #pragma omp taskwait // 2nd taskwait

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}
