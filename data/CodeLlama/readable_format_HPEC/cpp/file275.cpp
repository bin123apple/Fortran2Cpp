#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));

    // Parallel loop with default(none) shared(a) private(i,j)
    #pragma omp parallel for collapse(2) default(none) shared(a) private(i,j)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    // Parallel loop with default(shared) private(i,j)
    #pragma omp parallel for collapse(2) default(shared) private(i,j)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            b[i][j] = b[i][j] + 1;
        }
    }

    // Print values
    std::cout << a[49][49] << ", " << b[49][49] << std::endl;

    return 0;
}
