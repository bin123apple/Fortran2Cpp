#include <stdio.h>
#include <omp.h>

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

    #pragma omp task shared(x)
    {
        x = x + 1;    // 1st Child Task
    }

    #pragma omp task shared(y)
    {
        y = y - x;    // 2nd Child Task
    }

    #pragma omp taskwait

    printf("x=%d
", x);
    printf("y=%d
", y);

    #pragma omp taskwait
}
