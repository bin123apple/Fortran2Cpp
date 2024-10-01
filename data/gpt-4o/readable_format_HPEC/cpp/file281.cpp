#include <stdio.h>
#include <omp.h>

int i = 0;

void f1(int &i) {
#pragma omp single
    i++;
}

int main() {
#pragma omp parallel
    f1(i);

    printf("i = %d\n", i);

    return 0;
}
