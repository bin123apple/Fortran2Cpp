#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int n = 1000;
    int m = 1000;
    std::vector<std::vector<double>> b(n, std::vector<double>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = 0.5;
        }
    }

    #pragma omp parallel for private(j)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            b[i][j] = b[i-1][j-1];
        }
    }

    std::cout << "b(500,500) = " << b[499][499] << std::endl;

    return 0;
}
