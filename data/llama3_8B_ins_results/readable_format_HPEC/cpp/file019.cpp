#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, j, len, argCount, allocStatus, ix;
    std::vector<std::string> args;
    std::vector<std::vector<double>> a;

    len = 1000;

    argCount = argc;
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);
    for (ix = 1; ix <= argCount; ix++) {
        args[ix - 1] = argv[ix];
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    a.resize(len, std::vector<double>(len, 0.5));

    #pragma omp parallel for private(j)
    for (i = 1; i < len; i++) {
        for (j = 1; j < len; j++) {
            a[i][j] += a[i + 1][j];
        }
    }

    std::cout << "a(10,10) = " << a[10][10] << std::endl;

    a.clear();
    args.clear();

    return 0;
}
