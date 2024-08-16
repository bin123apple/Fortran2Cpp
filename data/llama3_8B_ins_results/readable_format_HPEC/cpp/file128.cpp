#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

const int MSIZE = 200;
const int mits = 1000;
const double relax = 1.0;
const double alpha = 0.0543;

vector<vector<double>> u(MSIZE, vector<double>(MSIZE));
vector<vector<double>> f(MSIZE, vector<double>(MSIZE));
vector<vector<double>> uold(MSIZE, vector<double>(MSIZE));

void initialize() {
    int i, j, xx, yy;
    double dx, dy, tol;

    dx = 2.0 / (MSIZE - 1);
    dy = 2.0 / (MSIZE - 1);

    #pragma omp parallel for private(i, j, xx, yy)
    for (i = 0; i < MSIZE; i++) {
        for (j = 0; j < MSIZE; j++) {
            xx = int(-1.0 + dx * (i - 1));
            yy = int(-1.0 + dy * (j - 1));
            u[i][j] = 0.0;
            f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
        }
    }
}

int main() {
    initialize();
    return 0;
}
