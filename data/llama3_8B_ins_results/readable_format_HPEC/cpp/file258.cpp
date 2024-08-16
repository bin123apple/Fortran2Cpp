#include <iostream>
#include <iomanip>

void print_array(int nx, int ny, double ex[ny][nx], double ey[ny][nx], double hz[ny][nx]) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            std::cout << std::setw(DATA_PRINTF_MODIFIER) << ex[j][i];
            std::cout << std::setw(DATA_PRINTF_MODIFIER) << ey[j][i];
            std::cout << std::setw(DATA_PRINTF_MODIFIER) << hz[j][i];
            if ((i * nx + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}
