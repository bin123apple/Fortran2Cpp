#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int i, j;
    std::vector<std::vector<double>> a(20, std::vector<double>(20, 0.0));

    #pragma omp parallel for
    for (i = 1; i < 20; i++) {
        for (j = 1; j <= 20; j++) {
            a[i][j] += a[i + 1][j];
        }
    }

    return 0;
}
