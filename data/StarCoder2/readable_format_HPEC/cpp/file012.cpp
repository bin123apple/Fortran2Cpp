#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]) {
    int i, tmp, len = 100, argCount, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> a;

    argCount = argc - 1; // Adjust for the fact that argv[0] is the program name

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);
    for (ix = 0; ix < argCount; ++ix) {
        args[ix] = std::string(argv[ix + 1]); // Adjust for the fact that argv[0] is the program name
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    a.resize(len);
    for (i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjust for 0-based indexing in C++
    }

    #pragma omp parallel for
    for (i = 0; i < len; ++i) {
        tmp = a[i] + i + 1; // Adjust for 0-based indexing in C++
        a[i] = tmp;
    }

    std::cout << "a[50]=" << a[50 - 1] << std::endl; // Adjust for 0-based indexing in C++

    return 0;
}
