#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, j, n, m, len, argCount, rdErr, ix;
    std::vector<std::string> args;
    std::vector<std::vector<float>> b;
    len = 100;

    argCount = argc - 1; // Subtracting 1 because argv[0] is the program name

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);

    for (ix = 0; ix < argCount; ++ix) {
        args[ix] = std::string(argv[ix + 1]); // +1 because argv[0] is the program name
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

    b.resize(n, std::vector<float>(m, 0.0f)); // Initialize with 0.0f

    #pragma omp parallel for collapse(2)
    for (j = 1; j < n; ++j) { // Start from 1 because b(i-1,j) is accessed
        for (i = 0; i < m; ++i) {
            b[i][j] = b[i][j - 1];
        }
    }

    std::cout << "b(50,50)=" << b[49][49] << std::endl; // Arrays in C++ are 0-indexed

    return 0;
}
