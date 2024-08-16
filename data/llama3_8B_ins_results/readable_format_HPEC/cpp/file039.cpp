#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>

int main(int argc, char** argv) {
    int i, tmp, len, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> a;

    len = 100;
    tmp = 10;

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
            len = std::stoi(args[0]);
        } catch (std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    a.resize(len);

    #pragma omp parallel for
    for (i = 1; i <= len; i++) {
        a[i - 1] = tmp;
        tmp = a[i - 1] + i;
    }

    args.clear();
    a.clear();

    return 0;
}
