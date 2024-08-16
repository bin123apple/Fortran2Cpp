#include <iostream>

void print_array(double ***bza, double ***ex, double ***ey, double ***hz, int cz, int cxm, int cym) {
    for (int i = 0; i <= cz; i++) {
        for (int j = 0; j <= cym; j++) {
            for (int k = 0; k <= cxm; k++) {
                std::cout << bza[k][j][i] << std::endl;
                std::cout << ex[k][j][i] << std::endl;
                std::cout << ey[k][j][i] << std::endl;
                std::cout << hz[k][j][i] << std::endl;
                if ((i * cxm + j - 1) % 20 == 0) {
                    std::cout << std::endl;
                }
            }
        }
    }
    std::cout << std::endl;
}
