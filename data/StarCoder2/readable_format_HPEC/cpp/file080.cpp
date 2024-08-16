#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, j, n, m, len, argCount, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<std::vector<float>> b;

    len = 1000;

    argCount = argc;
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);
    for (ix = 0; ix < argCount; ++ix) {
        args[ix] = argv[ix];
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    n = len;
    m = len;
    b.resize(n, std::vector<float>(m));

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            b[i][j] = 0.5f;
        }
    }

    #pragma omp parallel for collapse(2)
    for (i = 1; i < n; ++i) {
        for (j = 1; j < m; ++j) {
            b[i][j] = b[i - 1][j - 1];
        }
    }

    std::cout << "b(500,500) = " << b[500][500] << std::endl;

    return 0;
}
