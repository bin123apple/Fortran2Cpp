#include <iostream>
#include <iomanip>

void print_array(int m, double** symmat) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(10) << std::setprecision(6) << symmat[i][j];
            if ((i * m + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
