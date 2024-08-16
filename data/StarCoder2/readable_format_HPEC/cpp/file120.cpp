#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]) {
    int len = 1000;
    int rdErr;
    std::vector<std::string> args;

    // Check if command line arguments are provided
    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1;
    }

    // Allocate space for command line arguments
    args.resize(argc);

    // Copy command line arguments to the vector
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix]);
    }

    // Check if the first argument is an integer
    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    // Allocate memory for the array
    std::vector<int> a(len);

    // Initialize the first element
    a[0] = 2;

    // Parallel loop to update the array
    #pragma omp parallel for
    for (int i = 1; i < len; ++i) {
        a[i] = a[i] + a[0];
    }

    // Print the first element of the array
    std::cout << "a[0] = " << a[0] << std::endl;

    return 0;
}
