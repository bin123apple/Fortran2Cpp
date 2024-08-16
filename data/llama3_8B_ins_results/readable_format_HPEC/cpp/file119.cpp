#include <iostream>
#include <omp.h>

int main() {
    int i, len, numNodes, numNodes2;
    int x[100];

    len = 100;
    numNodes = len;
    numNodes2 = 0;

    for (i = 1; i <= len; i++) {
        if (i % 2 == 0) {
            x[i-1] = 5; // Fortran arrays are 1-indexed, C++ arrays are 0-indexed
        } else {
            x[i-1] = -5;
        }
    }

    #pragma omp parallel for
    for (i = numNodes; i >= 1; i--) {
        if (x[i-1] <= 0) {
            numNodes2 -= 1;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    return 0;
}
