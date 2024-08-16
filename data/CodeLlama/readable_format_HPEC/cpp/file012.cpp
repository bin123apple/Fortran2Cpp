#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 100;
    int argCount = argc - 1; // Adjust for 0-based indexing in C++
    std::vector<std::string> args(argCount);
    std::vector<int> a(len);

    // Check if command line arguments are provided
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 0;
    }

    // Allocate and initialize args array
    for (int ix = 0; ix < argCount; ++ix) {
        args[ix] = argv[ix + 1]; // Adjust for 0-based indexing
    }

    // Check if the first argument is an integer
    if (argCount >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    // Allocate and initialize a array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjust for 0-based indexing
    }

    // Parallel loop to modify the array
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = a[i] + i + 1; // Adjust for 0-based indexing
    }

    // Print the modified value of a[50]
    std::cout << "a[50]=" << a[50] << std::endl;

    return 0;
}
