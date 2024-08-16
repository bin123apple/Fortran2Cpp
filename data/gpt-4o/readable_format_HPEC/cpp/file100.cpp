#include <stdio.h>
#include <omp.h>

int main() {
    int numThreads;

#pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            numThreads = omp_get_num_threads();
        }
    }

    printf("numThreads = %d
", numThreads);
    return 0;
}
