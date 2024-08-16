#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 1000;
    int rdErr;

    // Check if command line arguments are provided
    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1; // Exit with error code
    }

    // Allocate and store command line arguments
    std::vector<std::string> args(argc);
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix]);
    }

    // Check if the first argument is an integer
    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1; // Exit with error code
        }
    }

    // Allocate array 'a'
    std::vector<int> a(len);

    // Initialize array 'a'
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusting for 0-based indexing in C++
    }

    // Parallel processing using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        a[i] = a[i + 1] + 1;
    }

    // Deallocate memory
    a.clear();
    args.clear();

    return 0; // Success
}
