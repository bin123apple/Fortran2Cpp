#include <iostream>
#include <omp.h>

int main() {
    int init = 10;
    int local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp master
        {
            init = 10;
        }
        local = init;
    }

    return 0;
}
