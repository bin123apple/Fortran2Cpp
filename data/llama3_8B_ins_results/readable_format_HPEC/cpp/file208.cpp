#include <iostream>
#include <iomanip>

void print_array(int ni, int nj, double c[][ni]) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            std::cout << std::setw(10) << std::setprecision(6) << c[j][i] << std::endl;
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}
