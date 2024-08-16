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
        x = x + 1; // 1st Child Task
    }

    #pragma omp task shared(x, y)
    {
        y = y - x; // 2nd Child Task
    }

    #pragma omp task if(false)
    {
        // 1st taskwait
    }

    printf("x=%d
", x);

    #pragma omp taskwait

    printf("y=%d
", y);
}
