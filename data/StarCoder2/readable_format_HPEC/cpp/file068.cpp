#include <omp.h>
#include <iostream>

int main() {
    const int size = 100;
    int a[size][size];

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    return 0;
}
