#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 1000;
    int i, argCount, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> a;

    argCount = argc;
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);
    if (args.capacity() == 0) {
        std::cout << "Allocation error, program terminated." << std::endl;
        return 1;
    }

    for (ix = 1; ix <= argCount; ix++) {
        args[ix - 1] = argv[ix];
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    a.resize(len);
    a[0] = 2;

    #pragma omp parallel for
    for (i = 1; i <= len; i++) {
        a[i] = a[i] + a[0];
    }

    std::cout << "a(0) = " << a[0] << std::endl;

    args.clear();
    a.clear();

    return 0;
}
