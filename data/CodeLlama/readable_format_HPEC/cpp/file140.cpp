#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib> // For std::exit

int main(int argc, char *argv[]) {
    int len = 2000;
    int uLen;
    std::vector<std::string> args;
    std::vector<int> a;

    // Check if command line arguments are provided
    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1; // Use return value to indicate error, if necessary
    }

    // Allocate memory for args and a based on argc
    try {
        args.resize(argc);
        a.resize(len);
    } catch (const std::bad_alloc&) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Copy command line arguments to args vector
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = argv[ix];
    }

    // Process first argument if present
    if (argc >= 1) {
        char* endptr = nullptr;
        len = std::strtol(args[0].c_str(), &endptr, 10);
        if (endptr == args[0].c_str()) {
            std::cerr << "Error, invalid integer value." << std::endl;
            return 1; // Use return value to indicate error
        }
    }

    // Initialize array a
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    uLen = len / 2;

    // Parallel section
    #pragma omp parallel for
    for (int i = 0; i < uLen; ++i) {
        a[2 * i] = a[i] + 1;
    }

    // No need to explicitly deallocate args and a as they will be automatically done by the destructors
    return 0; // Indicate success
}
