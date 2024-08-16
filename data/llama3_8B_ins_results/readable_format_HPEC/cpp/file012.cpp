#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int i, tmp, len, argCount, allocStatus, ix;
    std::vector<std::string> args;
    std::vector<int> a;

    len = 100;

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

    #pragma omp parallel for
    for (i = 1; i <= len; i++) {
        tmp = a[i - 1] + i;
        a[i - 1] = tmp;
    }

    std::cout << "a(50) = " << a[50] << std::endl;

    args.clear();
    a.clear();

    return 0;
}
