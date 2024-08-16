#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, N, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> a;

    N = 100;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    args.resize(argc);
    if (args.capacity() == 0) {
        std::cout << "Allocation error, program terminated." << std::endl;
        return 1;
    }

    for (ix = 1; ix <= argc; ix++) {
        args[ix - 1] = argv[ix];
    }

    if (argc >= 1) {
        try {
            N = std::stoi(args[0]);
        } catch (std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    a.resize(N);

    load_from_input(a, N);

    #pragma omp parallel for shared(a)
    for (i = 1; i <= N; i++) {
        a[i - 1] = i;
        if (N > 10000) a[0] = 1;
    }

    return 0;
}
