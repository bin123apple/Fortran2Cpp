#include <iostream>
#include <iomanip>

void print_array(int nx, int ny, double* s, double* q) {
    for (int i = 1; i <= ny; i++) {
        std::cout << std::setw(10) << s[i-1];
        if ((i-1) % 80 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    for (int i = 1; i <= nx; i++) {
        std::cout << std::setw(10) << q[i-1];
        if ((i-1) % 80 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
