#include <iostream>
#include <omp.h>

int main() {
    int init = 10;
    int local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp single
        init = 10;
        #pragma omp end single
        local = init;
    }
    #pragma omp end parallel

    std::cout << "init: " << init << ", local: " << local << std::endl;

    return 0;
}
