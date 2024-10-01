#include <stdio.h>
#include <omp.h>

void foo() {
    int x = 0;
    int y = 2;

    #pragma omp task shared(x)
    {
        x = x + 1;
    }

    #pragma omp task shared(y)
    {
        y = y - x;
    }

    #pragma omp taskwait

    printf("x= %d\n", x);

    #pragma omp taskwait

    printf("y= %d\n", y);
}

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
