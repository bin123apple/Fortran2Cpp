#include <iostream>
#include <iomanip>

void print_array(int ni, double c[][ni]) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            std::cout << std::setw(10) << c[j][i];
            if ((i * ni + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}
