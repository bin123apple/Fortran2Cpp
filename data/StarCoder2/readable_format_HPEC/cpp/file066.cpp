#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]) {
    int len = 10000;
    int argCount = argc;
    std::vector<std::string> args;
    int rdErr;
    int x;

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);

    for (int ix = 0; ix < argCount; ++ix) {
        args[ix] = std::string(argv[ix + 1]); // argv[0] is the program name
    }

    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    #pragma omp parallel for private(x)
    for (int i = 0; i <= len; ++i) {
        x = i;
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
