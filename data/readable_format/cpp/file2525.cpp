// fporde.cpp
#include <iostream>
#include <vector>

void fporde(const std::vector<float>& x, const std::vector<float>& y, int m, int kx, int ky,
            const std::vector<float>& tx, int nx, const std::vector<float>& ty, int ny,
            std::vector<int>& nummer, std::vector<int>& index, int nreg) {
    int kx1 = kx + 1;
    int ky1 = ky + 1;
    int nk1x = nx - kx1;
    int nk1y = ny - ky1;
    int nyy = nk1y - ky1 + 1;

    for (int i = 0; i < nreg; ++i) {
        index[i] = 0;
    }

    for (int im = 0; im < m; ++im) {
        float xi = x[im];
        float yi = y[im];
        int l = kx1;
        while (xi >= tx[l] && l < nk1x) {
            ++l;
        }

        int k = ky1;
        while (yi >= ty[k] && k < nk1y) {
            ++k;
        }

        int num = (l - kx1) * nyy + (k - ky1) + 1;
        nummer[im] = index[num-1];
        index[num-1] = im + 1; // Adjust for 0-based indexing in C++
    }
}

int main() {
    const int m = 5, kx = 2, ky = 2, nx = 7, ny = 7, nreg = 12;
    std::vector<float> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> y = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> tx = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<float> ty = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<int> nummer(m), index(nreg);

    fporde(x, y, m, kx, ky, tx, nx, ty, ny, nummer, index, nreg);

    std::cout << "C++ Stdout: nummer:" << std::endl;
    for (int num : nummer) {
        std::cout << num << std::endl;
    }

    std::cout << "index:" << std::endl;
    for (int ind : index) {
        std::cout << ind << std::endl;
    }

    return 0;
}