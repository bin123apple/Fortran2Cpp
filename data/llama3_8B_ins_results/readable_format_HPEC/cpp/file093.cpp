#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    std::vector<int> a(len);

    a[0] = 2;

    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        a[i] += a[0];
    }

    std::cout << "a(500) = " << a[500] << std::endl;

    return 0;
}
