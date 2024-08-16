#include <iostream>
#include <iomanip>

void print_array(double** d, int ni, int nl) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nl; j++) {
            std::cout << std::setw(10) << std::setprecision(5) << d[j][i] << std::endl;
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}
