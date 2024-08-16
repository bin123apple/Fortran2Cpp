#include <iostream>
#include <iomanip>

void print_array(int ni, int nj, double a[nj][ni], double r[nj][nj], double q[nj][ni]) {
    for (int i = 1; i <= ni; ++i) {
        for (int j = 1; j <= nj; ++j) {
            std::cout << std::setw(10) << a[j-1][i-1]; // adjust the width as needed
            if ((i-1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 1; i <= nj; ++i) {
        for (int j = 1; j <= nj; ++j) {
            std::cout << std::setw(10) << r[j-1][i-1]; // adjust the width as needed
            if ((i-1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 1; i <= ni; ++i) {
        for (int j = 1; j <= nj; ++j) {
            std::cout << std::setw(10) << q[j-1][i-1]; // adjust the width as needed
            if ((i-1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
