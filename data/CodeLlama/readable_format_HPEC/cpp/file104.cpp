#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            i = 1;
        }
        #pragma omp section
        {
            i = 2;
        }
    }

    std::cout << "i=" << i << std::endl;

    return 0;
}
