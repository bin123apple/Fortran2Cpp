#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

const int dp = sizeof(double);
const int MSIZE = 200;
const int mits = 1000;
const double tol = 0.0000000001;
const double relax = 1.0;
const double alpha = 0.0543;

std::vector<std::vector<double>> u(MSIZE, std::vector<double>(MSIZE));
std::vector<std::vector<double>> f(MSIZE, std::vector<double>(MSIZE));
std::vector<std::vector<double>> uold(MSIZE, std::vector<double>(MSIZE));

double dx, dy, omega, ax, ay, b;
int n, m;

void initialize() {
    n = MSIZE;
    m = MSIZE;

    dx = 2.0 / static_cast<double>(n - 1);
    dy = 2.0 / static_cast<double>(m - 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int xx = static_cast<int>(-1.0 + dx * i);
            int yy = static_cast<int>(-1.0 + dy * i);
            u[i][j] = 0.0;
            f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
        }
    }
}

void jacobi() {
    omega = relax;
    ax = 1.0 / (dx * dx);
    ay = 1.0 / (dy * dy);
    b = -2.0 / (dx * dx) - 2.0 / (dy * dy) - alpha;

    double error = 10.0 * tol;
    int k = 1;

    while (true) {
        error = 0.0;

        // Copy new solution into old
        #pragma omp parallel for collapse(2)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                uold[i][j] = u[i][j];
            }
        }

        #pragma omp parallel for collapse(2) reduction(+:error)
        for (int i = 1; i < (n - 1); ++i) {
            for (int j = 1; j < (m - 1); ++j) {
                double resid = (ax * (uold[i - 1][j] + uold[i + 1][j]) + ay * (uold[i][j - 1] + uold[i][j + 1]) + b * uold[i][j] - f[i][j]) / b;
                u[i][j] = uold[i][j] - omega * resid;
                error += resid * resid;
            }
        }

        // Error check
        error = std::sqrt(error) / (n * m);

        if (error < tol) {
            break;
        }

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
