#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

const int MSIZE = 200;
const int dp = 8; // Assuming double precision

std::vector<std::vector<double>> u, f, uold;
double dx, dy, tol, relax, alpha;
int n, m, mits;

void initialize() {
    n = MSIZE;
    m = MSIZE;
    u.resize(n, std::vector<double>(m));
    f.resize(n, std::vector<double>(m));
    uold.resize(n, std::vector<double>(m));

    dx = 2.0 / (n - 1);
    dy = 2.0 / (m - 1);

    // Initialize initial condition and RHS
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int xx = static_cast<int>(-1.0 + dx * i);
            int yy = static_cast<int>(-1.0 + dy * j);
            u[i][j] = 0.0;
            f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
        }
    }
}

int main() {
    mits = 1000;
    relax = 1.0;
    alpha = 0.0543;

    initialize();

    return 0;
}
