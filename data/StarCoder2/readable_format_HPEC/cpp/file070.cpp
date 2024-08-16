#include <iostream>
#include <omp.h>

int main() {
    const int inLen = 1000;
    const int outLen = 1;
    int input[inLen];
    int output[inLen];

    for (int i = 0; i < inLen; ++i) {
        input[i] = i + 1; // Adjusting for 1-based indexing in Fortran
    }

    #pragma omp parallel for
    for (int i = 0; i < inLen; ++i) {
        output[outLen - 1] = input[i]; // Adjusting for 0-based indexing and output position
        outLen++;
    }

    std::cout << "output[500-1]=" << output[500 - 1] << std::endl; // Adjusting for 0-based indexing and output format

    return 0;
}
