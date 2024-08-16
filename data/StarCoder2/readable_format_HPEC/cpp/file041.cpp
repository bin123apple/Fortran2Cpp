#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main() {
    int len = 100;
    int numNodes, numNodes2, argCount, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> x;

    // Get the number of command line arguments
    argCount = std::argc - 1;
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Allocate memory for the arguments
    args.resize(argCount);
    if (argCount > 0) {
        // Get the first command line argument
        len = std::stoi(std::argv[1], &rdErr);
        if (rdErr!= 0) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    // Allocate memory for the array x
    x.resize(len);

    numNodes = len;
    numNodes2 = 0;

    // Initialize the array x
    for (int i = 0; i < len; ++i) {
        if ((i + 1) % 2 == 0) {
            x[i] = 5;
        } else {
            x[i] = -5;
        }
    }

    // Parallel processing using OpenMP
    #pragma omp parallel for reduction(+:numNodes2)
    for (int i = numNodes - 1; i >= 0; --i) {
        if (x[i] <= 0) {
            numNodes2--;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    return 0;
}
