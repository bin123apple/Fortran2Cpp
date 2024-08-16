#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char** argv) {
    int i, len, allocStatus, rdErr, ix;
    std::vector<std::string> args;
    std::vector<int> a;
    std::vector<int> b;

    len = 100;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1;
    }

    args.resize(argc);
    for (ix = 1; ix <= argc; ++ix) {
        args[ix - 1] = argv[ix];
    }

    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    a.resize(len);
    b.resize(len);

    for (i = 0; i < len; ++i) {
        a[i] = i;
        b[i] = i + 1;
    }

    #pragma omp parallel for
    for (i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    for (i = 0; i < len; ++i) {
        std::cout << "Values for i and a(i) are: " << i << " " << a[i] << std::endl;
    }

    args.clear();
    a.clear();
    b.clear();

    return 0;
}
