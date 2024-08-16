#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]) {
    int i, j, len, rdErr, ix;
    std::vector<std::string> args;
    std::vector<std::vector<float>> a;

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

    a.resize(len, std::vector<float>(len));

    for (i = 0; i < len; ++i) {
        for (j = 0; j < len; ++j) {
            a[i][j] = 0.5f;
        }
    }

    #pragma omp parallel for collapse(2)
    for (i = 0; i < len - 1; ++i) {
        for (j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + a[i + 1][j];
        }
    }

    std::cout << "a[9][9] = " << a[9][9] << std::endl;

    return 0;
}
