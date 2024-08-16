#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    int tmp = 10;
    std::vector<int> a(len);

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = tmp;
        tmp = a[i] + i + 1; // Note: Fortran arrays are 1-based, C++ arrays are 0-based
    }

    #pragma omp parallel for reduction(+:tmp)
    for (int i = 0; i < len; ++i) {
        tmp += a[i];
    }

    std::cout << "a[50] = " << a[50] << std::endl;

    return 0;
}
