#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int i, len, numNodes, numNodes2, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> x;

    len = 100;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 0;
    }

    args.resize(argc);
    for (ix = 1; ix <= argc; ++ix) {
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

    x.resize(len);

    numNodes = len;
    numNodes2 = 0;

    // Initialize x()
    for (i = 1; i <= len; ++i) {
        if (i % 2 == 0) {
            x[i - 1] = 5;
        } else {
            x[i - 1] = -5;
        }
    }

    #pragma omp parallel for
    for (i = numNodes; i >= 1; --i) {
        if (x[i - 1] <= 0) {
            numNodes2 -= 1;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    args.clear();
    x.clear();

    return 0;
}
