#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int i, j, n, m, len;
    std::vector<std::vector<double>> b;

    len = 100;
    n = len;
    m = len;

    b.resize(n, std::vector<double>(m, 0.0));

    #pragma omp parallel for private(j)
    for (i = 0; i < n; i++) {
        for (j = 1; j < m; j++) {
            b[i][j] = b[i][j-1];
        }
    }
}

int main() {
    foo();
    return 0;
}
