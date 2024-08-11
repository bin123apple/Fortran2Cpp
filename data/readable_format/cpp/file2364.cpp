// fporde.cpp
#include <iostream>
#include <vector>

void fporde(const std::vector<double>& x, const std::vector<double>& y, int m, int kx, int ky, const std::vector<double>& tx, int nx, const std::vector<double>& ty, int ny, std::vector<int>& nummer, std::vector<int>& index, int nreg) {
    
    int kx1 = kx + 1;
    int ky1 = ky + 1;
    int nk1x = nx - kx1;
    int nk1y = ny - ky1;
    int nyy = nk1y - ky;

    for (int i = 0; i < nreg; i++) {
        index[i] = 0;
    }

    for (int im = 0; im < m; im++) {
        double xi = x[im];
        double yi = y[im];
        int l = kx1;
        int l1 = l + 1;

        while (!(xi < tx[l1-1] || l == nk1x)) { // Adjusted for 0-based indexing
            l = l1;
            l1 = l + 1;
        }

        int k = ky1;
        int k1 = k + 1;

        while (!(yi < ty[k1-1] || k == nk1y)) { // Adjusted for 0-based indexing
            k = k1;
            k1 = k + 1;
        }

        int num = (l - kx1) * nyy + k - ky;
        nummer[im] = index[num-1]; // Adjusted for 0-based indexing
        index[num-1] = im + 1; // Adjusting for Fortran 1-based indexing
    }
}

int main() {
    const int m = 5, kx = 1, ky = 1, nx = 5, ny = 5, nreg = 16;
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> tx = {0.0, 1.5, 2.5, 3.5, 4.5};
    std::vector<double> ty = {0.0, 1.5, 2.5, 3.5, 4.5};
    std::vector<int> nummer(m, 0);
    std::vector<int> index(nreg, 0);

    fporde(x, y, m, kx, ky, tx, nx, ty, ny, nummer, index, nreg);

    std::cout << "nummer:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << nummer[i] << std::endl;
    }

    std::cout << "index:" << std::endl;
    for (int i = 0; i < nreg; ++i) {
        std::cout << index[i] << std::endl;
    }

    return 0;
}