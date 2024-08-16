#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        f1(i);
    }

    std::cout << "i = " << i << std::endl;

    return 0;
}
