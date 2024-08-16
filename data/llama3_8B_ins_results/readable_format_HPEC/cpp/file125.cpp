#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int n = 100;
    int m = 100;

    std::vector<std::vector<double>> b(n, std::vector<double>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = i * j;
        }
    }

    #pragma omp parallel for
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            b[i][j] = b[i-1][j-1];
        }
    }

    return 0;
}
