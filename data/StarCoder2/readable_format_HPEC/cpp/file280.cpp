#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));
    std::vector<std::vector<double>> c(len, std::vector<double>(len));

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = static_cast<double>(i + 1) / 2.0;
            b[i][j] = static_cast<double>(i + 1) / 3.0;
            c[i][j] = static_cast<double>(i + 1) / 7.0;
        }
    }

    #pragma omp simd collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    std::cout << "c[50][50] = " << c[50][50] << std::endl;

    return 0;
}
