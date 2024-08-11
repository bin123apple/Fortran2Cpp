#include <omp.h>
#include <iostream>

int main() {
    int i, x, y, z;

    #pragma omp parallel for
    for (i = 1; i <= 4; ++i) {
        // The original body of the loop was empty. Add your code here.
    }

    return 0;
}