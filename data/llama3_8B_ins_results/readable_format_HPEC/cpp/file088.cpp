#include <iostream>
#include <omp.h>

int main() {
    int x = 0;
    int y = 2;

    #pragma omp parallel
    {
        #pragma omp single
        {
            foo(x, y);
        }
    }

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    return 0;
}

void foo(int& x, int& y) {
    #pragma omp task depend(out: x)
    {
        x++;
    }

    #pragma omp task
    {
        y--;
    }

    #pragma omp taskwait

    #pragma omp taskwait
}
