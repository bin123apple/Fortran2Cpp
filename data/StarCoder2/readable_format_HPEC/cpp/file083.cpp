#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]) {
    int len = 100;
    int argCount = argc - 1; // argc includes the program name, so subtract 1 to get actual arg count
    std::vector<std::string> args;
    std::vector<int> a;
    std::vector<int> b;

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    } else {
        args.resize(argCount);
        for (int ix = 0; ix < argCount; ++ix) {
            args[ix] = std::string(argv[ix + 1]); // argv[0] is the program name, so start from argv[1]
        }

        if (argCount >= 1) {
            try {
                len = std::stoi(args[0]);
            } catch (const std::exception& e) {
                std::cout << "Error, invalid integer value." << std::endl;
            }
        }
    }

    a.resize(len);
    b.resize(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
        b[i] = i + 2;
    }

    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    for (int i = 0; i < len; ++i) {
        std::cout << "Values for i and a[i] are: " << i + 1 << " " << a[i] << std::endl; // +1 to match Fortran's 1-based indexing
    }

    return 0;
}
