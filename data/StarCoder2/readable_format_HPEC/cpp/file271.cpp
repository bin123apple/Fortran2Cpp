#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));

    #pragma omp parallel for default(none) shared(a)
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    #pragma omp parallel for default(shared)
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            b[i][j] = b[i][j] + 1;
        }
    }

    std::cout << a[49][49] << " " << b[49][49] << std::endl;

    return 0;
}
