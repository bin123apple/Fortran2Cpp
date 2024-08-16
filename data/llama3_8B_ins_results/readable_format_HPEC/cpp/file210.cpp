#include <iostream>
#include <iomanip>

void print_array(int n, double* x) {
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(10) << std::setprecision(5) << x[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
