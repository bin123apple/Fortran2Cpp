#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));
    std::vector<std::vector<double>> c(len, std::vector<double>(len));

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            a[i][j] = (double)i / 2.0;
            b[i][j] = (double)i / 3.0;
            c[i][j] = (double)i / 7.0;
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    std::cout << "c(50,50) = " << c[50][50] << std::endl;

    return 0;
}
