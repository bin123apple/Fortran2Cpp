#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <omp.h>

int main(int argc, char **argv) {
    int len = 100;
    int rdErr;

    // Check if command line arguments are provided
    if (argc == 1) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1;
    }

    // Dynamically allocate memory for command line arguments
    std::vector<std::string> args(argc - 1);
    for (int ix = 0; ix < argc - 1; ++ix) {
        args[ix] = std::string(argv[ix + 1]);
    }

    // Check if the first argument is an integer
    if (argc >= 2) {
        std::stringstream ss(args[0]);
        ss >> len;
        if (!ss.good()) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    // Dynamically allocate memory for the array
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Parallel loop using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + 1;
    }

    // Print the result
    std::cout << "a[50]=" << a[50] << std::endl;

    return 0;
}
