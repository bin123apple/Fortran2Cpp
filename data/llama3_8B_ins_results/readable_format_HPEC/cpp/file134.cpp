#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len);
    std::vector<int> b(len);

    for (int i = 0; i < len; i++) {
        a[i] = i;
        b[i] = i;
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < len; i++) {
            a[i] = a[i] + i;
        }
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < len; i++) {
            b[i] = b[i] + i;
        }
    }

    std::cout << std::setw(3) << a[50] << std::setw(3) << b[50] << std::endl;

    return 0;
}
