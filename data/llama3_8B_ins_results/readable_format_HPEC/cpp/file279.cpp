#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int n = 100;
    int m = 100;

    std::vector<std::vector<double>> b(n, std::vector<double>(m));

    #pragma omp parallel for private(int i)
    for (int j = 2; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            b[i-1][j] = b[i-2][j];
        }
    }

    std::cout << "b(50,50) = " << b[50][50] << std::endl;

    return 0;
}
