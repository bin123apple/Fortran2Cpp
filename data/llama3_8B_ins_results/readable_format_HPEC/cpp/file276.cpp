#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, inLen, outLen, argCount, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> input;
    std::vector<int> output;

    inLen = 1000;
    outLen = 1;

    argCount = argc;
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argCount);
    for (ix = 1; ix <= argCount; ix++) {
        args[ix - 1] = argv[ix];
    }

    if (argCount >= 1) {
        try {
            inLen = std::stoi(args[0]);
        } catch (std::invalid_argument const &e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    input.resize(inLen);
    output.resize(inLen);

    #pragma omp parallel for
    for (i = 0; i < inLen; i++) {
        output[outLen - 1] = input[i];
        outLen++;
    }

    std::cout << "output(0)=" << output[0] << std::endl;

    input.clear();
    output.clear();
    args.clear();

    return 0;
}
