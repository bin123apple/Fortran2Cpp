#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len), b(len), c(len);

    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        a[i] = b[i] + c[i];
    }

    return 0;
}
