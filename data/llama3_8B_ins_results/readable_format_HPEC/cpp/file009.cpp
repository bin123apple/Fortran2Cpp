#include <iostream>
#include <omp.h>

int main() {
    int i, m, n;
    double b[4];

    m = 2;
    n = 4;

    #pragma omp simd safelen(2)
    for (i = m+1; i <= n; i++) {
        b[i] = b[i-m] - 1.0;
    }

    std::cout << b[3] << std::endl;

    return 0;
}
