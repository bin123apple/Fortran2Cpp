#include <cmath>
#include <vector>

// Assuming sp_data module contains necessary data, we'll define it as global variables for simplicity.
extern std::vector<int> grid_points;
extern double dnxm1, dnym1, dnzm1;
extern std::vector<std::vector<std::vector<std::vector<double>>>> u;
extern std::vector<std::vector<std::vector<std::vector<double>>>> rhs;

void error_norm(std::vector<double>& rms) {
    int i, j, k, m, d;
    double xi, eta, zeta, u_exact[5], add;

    for (m = 0; m < 5; ++m) {
        rms[m] = 0.0;
    }

    for (k = 0; k < grid_points[2]; ++k) {
        for (j = 0; j < grid_points[1]; ++j) {
            zeta = static_cast<double>(k) * dnzm1;
            eta = static_cast<double>(j) * dnym1;
            for (i = 0; i < grid_points[0]; ++i) {
                xi = static_cast<double>(i) * dnxm1;
                exact_solution(xi, eta, zeta, u_exact);

                for (m = 0; m < 5; ++m) {
                    add = u[m][i][j][k] - u_exact[m];
                    rms[m] += add * add;
                }
            }
        }
    }

    for (m = 0; m < 5; ++m) {
        for (d = 0; d < 3; ++d) {
            rms[m] /= static_cast<double>(grid_points[d] - 2);
        }
        rms[m] = std::sqrt(rms[m]);
    }
}

void rhs_norm(std::vector<double>& rms) {
    int i, j, k, d, m;
    double add;

    for (m = 0; m < 5; ++m) {
        rms[m] = 0.0;
    }

    for (k = 1; k < nz2; ++k) {
        for (j = 1; j < ny2; ++j) {
            for (i = 1; i < nx2; ++i) {
                for (m = 0; m < 5; ++m) {
                    add = rhs[m][i][j][k];
                    rms[m] += add * add;
                }
            }
        }
    }

    for (m = 0; m < 5; ++m) {
        for (d = 0; d < 3; ++d) {
            rms[m] /= static_cast<double>(grid_points[d] - 2);
        }
        rms[m] = std::sqrt(rms[m]);
    }
}
