#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int i, inLen, outLen;
    std::vector<int> input(1000);
    std::vector<int> output(1000);

    inLen = 1000;
    outLen = 1;

    for (i = 1; i <= inLen; i++) {
        input[i-1] = i;
    }

    #pragma omp parallel for
    for (i = 1; i <= inLen; i++) {
        output[outLen-1] = input[i-1];
        outLen++;
    }

    std::cout << "output(500) = " << output[499] << std::endl;

    return 0;
}
