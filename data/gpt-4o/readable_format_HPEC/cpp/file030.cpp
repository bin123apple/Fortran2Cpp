#include <stdio.h>
#include <omp.h>

int x[64], y[64];
int a = 5;

int main() {
    for (int i = 0; i < 64; i++) {
        x[i] = 0;
        y[i] = 3;
    }

#pragma omp target map(to:y,a) map(tofrom:x) device(0)
    {
        for (int i = 0; i < 64; i++) {
#pragma omp task depend(inout:x[i])
            x[i] = a * x[i];

#pragma omp task depend(inout:x[i])
            x[i] = x[i] + y[i];
        }
    }

    for (int i = 0; i < 64; i++) {
        if (x[i] != 3)
            printf("%d\n",x[i]);
    }

#pragma omp taskwait

    return 0;
}
