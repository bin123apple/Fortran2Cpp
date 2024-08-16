#include <iostream>
#include <omp.h>

int main() {
    int a[100];
    int i;

    #pragma omp parallel for
    for (i = 0; i < 100; i++) {
        a[i] = a[i] + 1;
    }

    return 0;
}
