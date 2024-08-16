#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int i, j, n, m, len;
    std::vector<std::vector<double>> b;

    len = 100;
    n = len;
    m = len;

    #pragma omp parallel for private(j)
    for (i = 0; i < n; i++) {
        for (j = 0; j < m - 1; j++) {
            b[i][j] = b[i][j + 1];
        }
    }
}

int main() {
    foo();
    return 0;
}
