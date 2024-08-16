#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

const int MSIZE = 200;
const int dp = sizeof(double);

std::vector<std::vector<double>> u, f, uold;
double dx, dy, tol, relax, alpha;
int n, m, mits;

void initialize() {
    n = MSIZE;
    m = MSIZE;
    tol = 0.0000000001;
    relax = 1.0;
    alpha = 0.0543;
    dx = 2.0 / (n - 1);
    dy = 2.0 / (m - 1);

    u.resize(n, std::vector<double>(m));
    f.resize(n, std::vector<double>(m));
    uold.resize(n, std::vector<double>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int xx = static_cast<int>(-1.0 + dx * i);
            int yy = static_cast<int>(-1.0 + dy * j);
            u[i][j] = 0.0;
            f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
        }
    }
}

void jacobi() {
    double omega = relax;
    double error = 10.0 * tol;
    double ax = 1.0 / (dx * dx);
    double ay = 1.0 / (dy * dy);
    double b = -2.0 / (dx * dx) - 2.0 / (dy * dy) - alpha;
    int k = 1;

    while (error > tol) {
        error = 0.0;

        // Copy new solution into old
        #pragma omp parallel for collapse(2)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                uold[i][j] = u[i][j];
            }
        }

        #pragma omp parallel for collapse(2) reduction(+:error)
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                double resid = (ax * (uold[i - 1][j] + uold[i + 1][j]) + ay * (uold[i][j - 1] + uold[i][j + 1]) + b * uold[i][j] - f[i][j]) / b;
                u[i][j] = uold[i][j] - omega * resid;
                error += resid * resid;
            }
        }

        error = std::sqrt(error) / (n * m);
        ++k;
    }

    std::cout << "Total number of iterations: " << k << std::endl;
    std::cout << "Residual: " << error << std::endl;
}

int main() {
    initialize();
    jacobi();
    return 0;
}
