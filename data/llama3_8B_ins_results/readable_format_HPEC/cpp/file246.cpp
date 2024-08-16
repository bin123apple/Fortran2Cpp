#include <iostream>
#include <iomanip>

void print_array(double* y, int ny) {
    for (int i = 0; i < ny; i++) {
        std::cout << std::setw(10) << std::setprecision(5) << y[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
