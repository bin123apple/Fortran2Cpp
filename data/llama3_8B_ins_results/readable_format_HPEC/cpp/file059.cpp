#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    int i, j;
    std::vector<int> a(len);
    std::vector<int> b(len * len + len);
    std::vector<int> c(len);

    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            b[j + i * len] = 1;
        }
        a[i] = 1;
        c[i] = 0;
    }

    #pragma omp target teams distribute parallel do
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            c[i] += a[j] * b[j + i * len];
        }
    }

    #pragma omp end teams distribute parallel do
    #pragma omp end target

    for (i = 0; i < len; i++) {
        if (c[i]!= len) {
            std::cout << c[i] << std::endl;
        }
    }

    return 0;
}
