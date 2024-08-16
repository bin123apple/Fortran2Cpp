#include <iostream>
#include <omp.h>

int main() {
    int a = 0;

    #pragma omp parallel
    {
        #pragma omp atomic
        a = a + 1;
    }

    std::cout << "a = " << a << std::endl;

    return 0;
}
