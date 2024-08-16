#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, j, n, m, len, rdErr, ix;
    std::vector<std::string> args;
    std::vector<std::vector<float>> b;

    len = 1000;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argc);
    for (ix = 0; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix]);
    }

    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    n = len;
    m = len;

    b.resize(len, std::vector<float>(len));

    for (i = 0; i < n; ++i) {
        #pragma omp parallel for
        for (j = 1; j < m; ++j) {
            b[i][j] = b[i][j - 1];
        }
    }

    // Printing the value of b[5][5] as an example
    // std::cout << "b[5][5] = " << b[5][5] << std::endl;

    return 0;
}
