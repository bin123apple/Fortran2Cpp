#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, j, n, m, len, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<std::vector<double>> b;

    len = 100;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 0;
    }

    args.resize(argc);
    for (ix = 1; ix <= argc; ix++) {
        args[ix - 1] = argv[ix];
    }

    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    n = len;
    m = len;

    b.resize(n, std::vector<double>(m));

    #pragma omp parallel for private(i)
    for (j = 2; j <= n; j++) {
        for (i = 1; i <= m; i++) {
            b[i][j] = b[i][j - 1];
        }
    }

    std::cout << "b(50,50) = " << b[50][50] << std::endl;

    for (auto& arg : args) {
        delete[] arg.c_str();
    }
    for (auto& row : b) {
        row.clear();
    }
    b.clear();

    return 0;
}
