#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 1000;
    std::vector<std::string> args(argc);
    std::vector<int> a(len);
    int i, ix;

    // Check command line arguments
    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Get command line arguments
    for (ix = 0; ix < argc; ++ix) {
        args[ix] = argv[ix];
    }

    // Check if at least one argument is provided
    if (argc >= 1) {
        // Attempt to read the first argument as an integer
        try {
            len = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        } catch (const std::out_of_range& e) {
            std::cout << "Error, integer value out of range." << std::endl;
            return 1;
        }
    }

    // Initialize array
    for (i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    // Parallel loop to increment elements
    #pragma omp parallel for
    for (i = 0; i < len - 1; ++i) {
        a[i] = a[i + 1] + 1;
    }

    // Clean up
    a.clear();
    args.clear();

    return 0;
}
