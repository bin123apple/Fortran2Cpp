#include <iostream>
#include <omp.h>

int main() {
    int len = 10000;
    int x = 0;

    #pragma omp parallel for private(i) reduction(+:x)
    for (int i = 0; i <= len; ++i) {
        x = i;
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
