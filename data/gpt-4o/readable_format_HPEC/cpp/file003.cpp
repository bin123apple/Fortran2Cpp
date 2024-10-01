#include <stdio.h>
#include <omp.h>

void foo() {
    int x = 0, y = 2;

    #pragma omp task shared(x)
    x = x+1;

    #pragma omp task depend(in: x) shared(x, y)
    y = y-x;

    #pragma omp task depend(in: x) if(false)
    ;

    printf("x=%d\n", x);
    printf("y=%d\n", y);

    #pragma omp taskwait
}

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        foo();
    }
    return 0;
}
