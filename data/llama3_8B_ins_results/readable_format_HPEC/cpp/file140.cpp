#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int i, len, uLen, argCount, allocStatus, ix;
    std::vector<std::string> args;
    std::vector<int> a;

    len = 2000;

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

    for (i = 1; i <= len; i++) {
        a[i - 1] = i;
    }

    uLen = len / 2;

    #pragma omp parallel for
    for (i = 1; i <= uLen; i++) {
        a[2 * i - 1] = a[i - 1] + 1;
    }

    args.clear();
    a.clear();

    return 0;
}
