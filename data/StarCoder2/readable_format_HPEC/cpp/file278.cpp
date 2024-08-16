#include <iostream>
#include <vector>
#include <string>
#include <omp.h>
#include <cmath>
#include <cstdlib>

int main(int argc, char **argv) {
    int i, j, len, argCount, allocStatus, rdErr, ix;
    double temp, getSum = 0.0;
    std::vector<std::string> args;

    len = 100;

    argCount = argc - 1; // Adjusted for 0-based indexing in C++
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);
    for (ix = 0; ix < argCount; ++ix) {
        args[ix] = std::string(argv[ix + 1]); // Adjusted for 0-based indexing in C++
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    std::vector<std::vector<double>> u(len, std::vector<double>(len));

    for (i = 0; i < len; ++i) {
        for (j = 0; j < len; ++j) {
            u[i][j] = 0.5;
        }
    }

    #pragma omp parallel for collapse(2) private(temp) reduction(+:getSum)
    for (i = 0; i < len; ++i) {
        for (j = 0; j < len; ++j) {
            temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    return 0;
}
