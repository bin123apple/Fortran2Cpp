#include <omp.h>
#include "DRB066.h" // Assuming this header file exists and is compatible with C++

int main() {
    int N = 1000;

    #pragma omp parallel
    {
        setup(N);
    }

    return 0;
}
