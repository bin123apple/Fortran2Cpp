#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

const int dp = sizeof(double);

class DRB057 {
public:
    int MSIZE;
    int n, m, mits;
    double dx, dy, tol, relax, alpha;
    std::vector<std::vector<double>> u, f, uold;

    DRB057() : MSIZE(0), n(0), m(0), mits(0), dx(0.0), dy(0.0), tol(0.0), relax(0.0), alpha(0.0) {}

    void initialize() {
        MSIZE = 200;
        mits = 1000;
        relax = 1.0;
        alpha = 0.0543;
        n = MSIZE;
        m = MSIZE;
        u.resize(MSIZE, std::vector<double>(MSIZE, 0.0));
        f.resize(MSIZE, std::vector<double>(MSIZE, 0.0));
        uold.resize(MSIZE, std::vector<double>(MSIZE, 0.0));

        dx = 2.0 / static_cast<double>(n - 1);
        dy = 2.0 / static_cast<double>(m - 1);

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
};

int main() {
    DRB057 drb057;
    drb057.initialize();
    return 0;
}
