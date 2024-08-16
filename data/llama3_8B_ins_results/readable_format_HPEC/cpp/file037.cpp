#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            i = 1;
            #pragma omp task
            i = 2;
        }
    }

    std::cout << "i = " << i << std::endl;

    return 0;
}
