#include <iostream>
#include <iomanip>

void print_array(double*** a, int nr, int nq, int np) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nq; j++) {
            for (int k = 0; k < np; k++) {
                std::cout << std::setw(10) << std::setprecision(5) << a[k][j][i] << " ";
                if ((i - 1) % 20 == 0) {
                    std::cout << std::endl;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
