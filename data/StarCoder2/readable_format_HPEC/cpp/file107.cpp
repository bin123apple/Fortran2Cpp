#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len), b(len), c(len);

    int i = 0, j = 0;

    for (i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i + 1) / 2.0;
        b[i] = static_cast<double>(i + 1) / 3.0;
        c[i] = static_cast<double>(i + 1) / 7.0;
    }

    #pragma omp parallel for
    for (i = 0; i < len; ++i) {
        c[j] += a[i] * b[i];
        j++;
    }

    std::cout << "c[50] = " << c[50] << std::endl;

    return 0;
}
