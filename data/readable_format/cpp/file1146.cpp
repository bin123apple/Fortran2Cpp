// clawpack5_setaux.cpp
#include <iostream>
#include <vector>

struct ComAux {
    double rhol, cl, rhor, cr;
};

void clawpack5_setaux(int mbc, int mx, int my, double xlower, double ylower,
                      double dx, double dy, int maux, std::vector<std::vector<std::vector<double>>>& aux,
                      ComAux& comaux) {
    for (int j = -mbc; j < my + mbc; ++j) {
        for (int i = -mbc; i < mx + mbc; ++i) {
            double xcell = xlower + (i + 0.5) * dx;
            if (xcell < 0.5) {
                aux[0][i + mbc][j + mbc] = comaux.rhol;
                aux[1][i + mbc][j + mbc] = comaux.cl;
            } else {
                aux[0][i + mbc][j + mbc] = comaux.rhor;
                aux[1][i + mbc][j + mbc] = comaux.cr;
            }
        }
    }
}

int main() {
    int mbc = 2, mx = 5, my = 5, maux = 2;
    double xlower = 0.0, ylower = 0.0, dx = 0.1, dy = 0.1;
    ComAux comaux{1.0, 2.0, 3.0, 4.0}; // Initialize ComAux

    std::vector<std::vector<std::vector<double>>> aux(maux, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc)));

    clawpack5_setaux(mbc, mx, my, xlower, ylower, dx, dy, maux, aux, comaux);

    // Output aux for verification
    for (int j = -mbc; j < my + mbc; ++j) {
        for (int i = -mbc; i < mx + mbc; ++i) {
            std::cout << "aux(:, " << i << ", " << j << ") = ";
            for (int k = 0; k < maux; ++k) {
                std::cout << aux[k][i + mbc][j + mbc] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}