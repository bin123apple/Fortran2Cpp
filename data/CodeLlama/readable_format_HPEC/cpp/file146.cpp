#include <cmath>
#include <array>

// Assuming these are defined in the sp_data module or similar
extern std::array<int, 3> grid_points;
extern double dnxm1, dnym1, dnzm1;
extern std::array<std::array<std::array<std::array<double, 5>, 3>, 2>, 3> u;
extern std::array<std::array<std::array<std::array<double, 5>, 3>, 2>, 3> rhs;

void exact_solution(double xi, double eta, double zeta, std::array<double, 5>& u_exact) {
    // Placeholder for the exact solution calculation
    // This function should be implemented according to the specific problem
}

void error_norm(std::array<double, 5>& rms) {
    double xi, eta, zeta, add;
    int i, j, k, m, d;

    for (m = 0; m < 5; ++m) {
        rms[m] = 0.0;
    }

    for (k = 0; k < grid_points[2] - 1; ++k) {
        zeta = static_cast<double>(k) * dnzm1;
        for (j = 0; j < grid_points[1] - 1; ++j) {
            eta = static_cast<double>(j) * dnym1;
            for (i = 0; i < grid_points[0] - 1; ++i) {
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

void rhs_norm(std::array<double, 5>& rms) {
    double add;
    int i, j, k, m, d;

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
