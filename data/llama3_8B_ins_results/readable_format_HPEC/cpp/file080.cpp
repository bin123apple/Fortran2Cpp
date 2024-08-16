#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int i, j, n, m, len, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<std::vector<double>> b;

    len = 1000;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1;
    }

    args.resize(argc);
    for (ix = 0; ix < argc; ix++) {
        args[ix] = argv[ix];
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

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[i][j] = 0.5;
        }
    }

    #pragma omp parallel for private(j)
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            b[i][j] = b[i-1][j-1];
        }
    }

    std::cout << "b(500,500) = " << b[500][500] << std::endl;

    for (auto& arg : args) {
        delete[] arg.c_str();
    }
    for (auto& row : b) {
        row.clear();
    }
    args.clear();
    b.clear();

    return 0;
}
