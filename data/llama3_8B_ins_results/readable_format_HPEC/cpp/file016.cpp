#include <iostream>
#include <omp.h>

int main() {
    int i, x, len;
    len = 10000;

    #pragma omp parallel for private(i)
    for (int i = 0; i <= len; i++) {
        x = i;
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
