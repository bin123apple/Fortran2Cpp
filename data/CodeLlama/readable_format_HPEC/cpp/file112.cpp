#include <iostream>
#include <omp.h>

int main() {
    int k;

    #pragma omp parallel
    {
        #pragma omp master
        {
            k = omp_get_num_threads();
            std::cout << "Number of threads requested = " << k << std::endl;
        }
    }

    return 0;
}
