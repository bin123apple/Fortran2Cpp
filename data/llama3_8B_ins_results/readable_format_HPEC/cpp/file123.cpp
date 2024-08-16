#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    int n = len;
    int m = len;

    std::vector<std::vector<double>> b(n, std::vector<double>(m));

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            b[i][j] = b[i][j-1];
        }
    }

    std::cout << "b(500,500) = " << b[499][499] << std::endl;

    return 0;
}
