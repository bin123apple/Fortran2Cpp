#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int i, j, len, argCount, allocStatus, ix;
    double temp, getSum;
    std::vector<std::string> args;
    double** u;

    len = 100;
    getSum = 0.0;

    argCount = argc;
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);
    for (ix = 0; ix < argCount; ix++) {
        args[ix] = argv[ix];
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    u = new double*[len];
    for (i = 0; i < len; i++) {
        u[i] = new double[len];
    }

    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            u[i][j] = 0.5;
        }
    }

    #pragma omp parallel for private(temp, i, j) reduction(+:getSum)
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    for (i = 0; i < len; i++) {
        delete[] u[i];
    }
    delete[] u;

    return 0;
}
