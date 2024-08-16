#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

const int MSIZE = 200;
const int mits = 1000;
const double tol = 1e-10;
const double relax = 1.0;
const double alpha = 0.0543;
const double dx = 2.0 / (MSIZE - 1);
const double dy = 2.0 / (MSIZE - 1);

vector<vector<double>> u(MSIZE, vector<double>(MSIZE));
vector<vector<double>> f(MSIZE, vector<double>(MSIZE));
vector<vector<double>> uold(MSIZE, vector<double>(MSIZE));

void initialize() {
    for (int i = 0; i < MSIZE; i++) {
        for (int j = 0; j < MSIZE; j++) {
            double xx = -1.0 + dx * (i - 1);
            double yy = -1.0 + dy * (j - 1);
            u[i][j] = 0.0;
            f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
        }
    }
}

void jacobi() {
    double omega = relax;
    double error = 10.0 * tol;
    int k = 1;

    do {
        error = 0.0;

        #pragma omp parallel
        {
            #pragma omp for private(i, j)
            for (int i = 1; i < MSIZE - 1; i++) {
                for (int j = 1; j < MSIZE - 1; j++) {
                    uold[i][j] = u[i][j];
                }
            }

            #pragma omp for private(i, j, resid) reduction(+:error)
            for (int i = 1; i < MSIZE - 1; i++) {
                for (int j = 1; j < MSIZE - 1; j++) {
                    double resid = (1.0 / (dx * dx) * (uold[i - 1][j] + uold[i + 1][j]) + 1.0 / (dy * dy) * (uold[i][j - 1] + uold[i][j + 1]) - 2.0 / (dx * dx) - 2.0 / (dy * dy) - alpha) * uold[i][j] - f[i][j];
                    u[i][j] = uold[i][j] - omega * resid;
                    error += resid * resid;
                }
            }
        }

        error = sqrt(error) / (MSIZE * MSIZE);
    } while (error > tol);

    cout << "Total number of iterations: " << k << endl;
    cout << "Residual: " << error << endl;
}

int main() {
    initialize();
    jacobi();
    return 0;
}
