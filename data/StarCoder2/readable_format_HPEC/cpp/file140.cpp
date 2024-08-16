#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 2000;
    int uLen;
    int rdErr;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    std::vector<std::string> args(argc);
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix]);
    }

    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    std::vector<int> a(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    uLen = len / 2;

    #pragma omp parallel for
    for (int i = 0; i < uLen; ++i) {
        a[2 * i] = a[i] + 1;
    }

    return 0;
}
