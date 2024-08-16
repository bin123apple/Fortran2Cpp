#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int numNodes = len;
    int numNodes2 = 0;
    int x[len];

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0) {
            x[i] = 5;
        } else {
            x[i] = -5;
        }
    }

    // Parallel processing using OpenMP
    #pragma omp parallel for reduction(+:numNodes2)
    for (int i = numNodes - 1; i >= 0; --i) {
        if (x[i] <= 0) {
            numNodes2--;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    return 0;
}
