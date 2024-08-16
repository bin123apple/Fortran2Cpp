#include <iostream>
#include <vector>
#include <omp.h>
#include <string>
#include <cstdlib> // For std::exit

int main(int argc, char* argv[]) {
    int n, m, len, argCount, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<std::vector<float>> b;

    argCount = argc;

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 0;
    }

    try {
        args.resize(argCount);
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    for (ix = 0; ix < argCount; ++ix) {
        args[ix] = argv[ix];
    }

    if (argCount >= 1) {
        std::stringstream(args[0]) >> len;
        if (!args[0].empty() && args[0][0] == '-') {
            std::cerr << "Error, invalid integer value." << std::endl;
            return 0;
        }
    }

    n = len;
    m = len;

    try {
        b.resize(n, std::vector<float>(m));
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    #pragma omp parallel for collapse(2) private(ix)
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            b[i][j] = b[i][j - 1];
        }
    }

    std::cout << "b(50,50)=" << b[49][49] << std::endl; // 0-based indexing in C++

    return 0;
}
