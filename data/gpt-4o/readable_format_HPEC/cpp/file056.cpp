#include <stdio.h>
#include <omp.h>

int main() {
    int a = 0;

#pragma omp parallel shared(a)
    {
#pragma omp master
        a = 0;

#pragma omp barrier

#pragma omp for reduction(+:a)
        for (int i = 0; i < 10; i++)
            a += i;

#pragma omp single
        printf("Sum is %d
", a);
    }

    return 0;
}
