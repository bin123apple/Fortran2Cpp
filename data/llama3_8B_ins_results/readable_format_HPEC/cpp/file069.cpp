#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int i, tmp, len;
    std::vector<int> a;

    len = 100;
    tmp = 10;

    a.resize(len);

    #pragma omp parallel for
    for (i = 1; i <= len; i++) {
        a[i-1] = tmp;
        tmp = a[i-1] + i;
    }

    std::cout << "a(50) = " << a[49] << std::endl;

    a.clear();

    return 0;
}
