#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main() {
    int inLen = 1000;
    int outLen = 0;
    int argCount = 0;
    int allocStatus = 0;
    int rdErr = 0;

    // Get the number of command line arguments
    argCount = static_cast<int>(std::getenv("argc"));
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Allocate memory for the command line arguments
    std::vector<std::string> args(argCount);

    // Get the command line arguments
    for (int ix = 0; ix < argCount; ++ix) {
        args[ix] = std::string(std::getenv("argv")[ix]);
    }

    // Check if the first argument is an integer
    if (argCount >= 1) {
        rdErr = std::sscanf(args[0].c_str(), "%d", &inLen);
        if (rdErr!= 1) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    // Allocate memory for the input and output arrays
    std::vector<int> input(inLen);
    std::vector<int> output(inLen);

    // Initialize the input array
    for (int i = 0; i < inLen; ++i) {
        input[i] = i + 1;
    }

    // Parallel loop to copy elements from input to output
    #pragma omp parallel for
    for (int i = 0; i < inLen; ++i) {
        output[outLen] = input[i];
        outLen++;
    }

    // Print the first element of the output array
    std::cout << "output[0]=" << output[0] << std::endl;

    return 0;
}
