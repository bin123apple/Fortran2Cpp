#include <omp.h>
#include <iostream>

int main() {
    int init;
    int local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp single
        {
            init = 10;
        }
        local = init;
    }

    return 0;
}
