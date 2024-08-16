#include <iostream>
#include <iomanip>

void print_array(int n, double** a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(10) << std::setprecision(5) << a[i][j] << " ";
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}
