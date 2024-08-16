#include <iostream>
#include <omp.h>

int main() {
    int i, j;
    int a[100][100];

    #pragma omp parallel for private(j)
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            a[i][j]++;
        }
    }

    return 0;
}
