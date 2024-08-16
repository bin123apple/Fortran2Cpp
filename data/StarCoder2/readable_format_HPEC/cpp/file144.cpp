#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 100;
    int x = 10;
    int rdErr;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    std::vector<std::string> args(argc);
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = argv[ix];
    }

    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    std::vector<int> a(len);

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = x;
        x = i + 1;
    }

    std::cout << "x=" << x << " a[0]=" << a[0] << std::endl;

    return 0;
}
