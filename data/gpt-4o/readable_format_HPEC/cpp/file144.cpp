#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 100, x = 10;
    int i, ix;

    if (argc == 1) {
        std::cout << "No command line arguments provided." << std::endl;
        return 0;
    }

    std::vector<std::string> args(argv, argv+argc);

    if (argc >= 2) {
        try {
            len = std::stoi(args[1]);
        } catch (std::invalid_argument const &e) {
            std::cout << "Error, invalid integer value." << std::endl;
            return 0;
        }
    }

    std::vector<int> a(len);
    
    #pragma omp parallel for private(i)
    for (i = 0; i < len; i++) {
        a[i] = x;
        x = i;
    }

    std::cout << "x=" << x << "  a[0]=" << a[0] << std::endl;

    return 0;
}
