#include <iostream>
#include <iomanip>

void print_array(int n, double* w) {
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(10) << std::setprecision(6) << w[i] << std::endl;
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
