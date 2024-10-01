#include <stdio.h>
#include <omp.h>

void foo() {
    int i, x;
#pragma omp parallel for private(i) lastprivate(x)
    for (i = 0; i < 100; i++) {
        x = i;
    }
    printf("x = %d\n", x);
}

int main() {
#pragma omp parallel
    {
        foo();
    }
    return 0;
}
