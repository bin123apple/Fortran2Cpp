#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    int i, j;
    double dp = 1.0;

    // Allocate arrays
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));

    // OpenMP parallel loops
    #pragma omp parallel for default(none) shared(a) private(i, j)
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            a[i][j] += 1;
        }
    }

    #pragma omp parallel for default(shared) private(i, j)
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            b[i][j] += 1;
        }
    }

    // Print results
    std::cout << a[50][50] << " " << b[50][50] << std::endl;

    // Deallocate arrays
    a.clear();
    b.clear();

    return 0;
}
