#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int i, error, len, b;
    std::vector<int> a;

    len = 1000;
    b = 5;

    a.resize(len);

    for (i = 1; i <= len; i++) {
        a[i-1] = i;
    }

    #pragma omp parallel shared(b, error)
    {
        #pragma omp for nowait
        for (i = 1; i <= len; i++) {
            a[i-1] = b + a[i-1] * 5;
        }
    }

    #pragma omp barrier
    #pragma omp single
    {
        error = a[8] + 1;
    }

    std::cout << "error = " << error << std::endl;

    return 0;
}
