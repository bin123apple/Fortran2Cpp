#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int i, len, argCount, allocStatus, rdErr, x, ix;
    std::vector<std::string> args;

    len = 10000;

    argCount = argc;

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.reserve(argCount);

    for (ix = 1; ix <= argCount; ix++) {
        args.push_back(argv[ix - 1]);
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    #pragma omp parallel private(i)
    {
        for (i = 0; i <= len; i++) {
            x = i;
        }
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
