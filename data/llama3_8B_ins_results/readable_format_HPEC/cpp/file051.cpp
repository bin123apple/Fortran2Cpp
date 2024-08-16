#include <iostream>
#include <omp.h>

int main() {
    int i, m, n;
    double b[4];

    m = 1;
    n = 4;

    #pragma omp parallel for simd safelen(2)
    for (i = m+1; i <= n; i++) {
        b[i-1] = b[i-m-1] - 1.0;
    }

    std::cout << b[2] << std::endl;

    return 0;
}
