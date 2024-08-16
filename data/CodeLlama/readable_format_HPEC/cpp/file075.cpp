#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp parallel shared(var)
    {
        #pragma omp single
        {
            var = var + 1;
        }
        #pragma omp barrier

        #pragma omp single
        {
            var = var + 1;
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
