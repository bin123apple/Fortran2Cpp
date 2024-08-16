#include <omp.h>

int main() {
    int init, local;

#pragma omp parallel shared(init) private(local)
    {
#pragma omp master
        init = 10;
#pragma omp end master
        local = init;
    }
    
    return 0;
}
