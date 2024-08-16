#include <omp.h>
#include <iostream>

int main() {
    int a[100];

    #pragma omp parallel for
    for (int i = 0; i < 100; ++i) {
        a[i] = a[i] + 1;
    }

    return 0;
}
