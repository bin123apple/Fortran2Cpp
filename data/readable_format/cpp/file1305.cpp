#include <omp.h>

int main() {
    #pragma omp parallel for
    for (int i = 1; i <= 3; ++i) {
        // The loop body is empty in the original example,
        // but any parallelizable work could go here.
    }
    return 0;
}