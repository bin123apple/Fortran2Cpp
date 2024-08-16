#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int len = 100;
    int x = 10;
    int argCount = argc;
    int allocStatus = 0;
    int rdErr = 0;
    int ix;

    // Check if command line arguments are provided
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Allocate memory for command line arguments
    std::vector<std::string> args(argCount);
    if (args.capacity() == 0) {
        std::cout << "Allocation error, program terminated." << std::endl;
        return 1;
    }

    // Copy command line arguments to the vector
    for (ix = 1; ix <= argCount; ix++) {
        args[ix - 1] = argv[ix];
    }

    // Check if command line arguments are provided
    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    // Allocate memory for array 'a'
    std::vector<int> a(len);
    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        a[i] = x;
        x = i;
    }

    // Print the result
    std::cout << "x=" << x << ", a(0)=" << a[0] << std::endl;

    // Deallocate memory
    args.clear();
    a.clear();

    return 0;
}
