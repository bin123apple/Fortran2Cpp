#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int inLen = 1000;
    int outLen = 1;
    std::vector<int> input(inLen);
    std::vector<int> output(1000);

    // Initialize the input array
    for (int i = 0; i < inLen; ++i) {
        input[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    // Parallel loop to populate the output array
    #pragma omp parallel for
    for (int i = 0; i < inLen; ++i) {
        output[outLen - 1] = input[i]; // Adjust for 0-based indexing
        outLen++;
    }

    // Print the 500th element of the output array
    std::cout << "output(500)=" << output[499] << std::endl; // Adjust for 0-based indexing

    return 0;
}
