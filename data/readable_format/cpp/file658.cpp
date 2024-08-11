// interpolate_bound_params.cpp
#include <iostream>
#include <vector>
#include <cmath>

void interpolate_bound_params(int nx, int ny, int pnx, int pny, double dx, double dy, const std::vector<std::vector<double>>& pbc_rhs, std::vector<std::vector<double>>& bc_rhs) {
    double pdx = dx * static_cast<double>(nx) / static_cast<double>(pnx - 1);
    double pdy = dy * static_cast<double>(ny) / static_cast<double>(pny - 1);

    for (int ix = 0; ix < nx; ++ix) {
        double x = (ix + 0.5) * dx;
        for (int pix = 0; pix < pnx; ++pix) {
            double px = pix * pdx;
            bc_rhs[ix][0] += pbc_rhs[pix][0] * std::max(0.0, 1.0 - std::abs(px - x) / pdx);
            bc_rhs[ix][1] += pbc_rhs[pix][1] * std::max(0.0, 1.0 - std::abs(px - x) / pdx);
        }
    }

    for (int iy = 0; iy < ny; ++iy) {
        double y = (iy + 0.5) * dy;
        for (int piy = 0; piy < pny; ++piy) {
            double py = piy * pdy;
            bc_rhs[nx + iy][0] += pbc_rhs[pnx + piy][0] * std::max(0.0, 1.0 - std::abs(py - y) / pdy);
            bc_rhs[nx + iy][1] += pbc_rhs[pnx + piy][1] * std::max(0.0, 1.0 - std::abs(py - y) / pdy);
        }
    }
}

int main() {
    int nx = 2, ny = 2, pnx = 3, pny = 3;
    double dx = 1.0, dy = 1.0;
    std::vector<std::vector<double>> pbc_rhs(pnx + pny, std::vector<double>(2));
    std::vector<std::vector<double>> bc_rhs(nx + ny, std::vector<double>(2, 0.0));

    for (int i = 0; i < pnx; ++i) {
        pbc_rhs[i][0] = 1.0 + i % pnx;
        pbc_rhs[i][1] = 2.0 + i % pnx;
    }
    for (int i = 0; i < pny; ++i) {
        pbc_rhs[pnx + i][0] = 1.0 + i % pny;
        pbc_rhs[pnx + i][1] = 2.0 + i % pny;
    }

    interpolate_bound_params(nx, ny, pnx, pny, dx, dy, pbc_rhs, bc_rhs);

    std::cout << "C++ Stdout: bc_rhs:" << std::endl;
    for (int i = 0; i < nx + ny; ++i) {
        std::cout << bc_rhs[i][0] << ", " << bc_rhs[i][1] << std::endl;
    }

    return 0;
}