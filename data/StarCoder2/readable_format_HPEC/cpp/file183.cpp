#include <cmath>
#include <vector>

// Assuming the existence of a namespace or class containing the necessary data
// For example, a class named `BtData` containing the necessary data members
// and methods, similar to the Fortran module `bt_data`.

namespace BtData {
    // Assuming the existence of these functions or data members
    extern std::vector<int> grid_points;
    extern double dnxm1, dnym1, dnzm1;
    extern std::vector<std::vector<std::vector<std::vector<double>>>> u;
    extern std::vector<std::vector<std::vector<std::vector<double>>>> rhs;
    extern void exact_solution(double xi, double eta, double zeta, std::vector<double>& u_exact);
}

void error_norm(std::vector<double>& rms) {
    int i, j, k, m, d;
    double xi, eta, zeta, u_exact[5], add;

    for (m = 0; m < 5; ++m) {
        rms[m] = 0.0;
    }

    for (k = 0; k < BtData::grid_points[2]; ++k) {
        for (j = 0; j < BtData::grid_points[1]; ++j) {
            zeta = static_cast<double>(k) * BtData::dnzm1;
            eta = static_cast<double>(j) * BtData::dnym1;
            for (i = 0; i < BtData::grid_points[0]; ++i) {
                xi = static_cast<double>(i) * BtData::dnxm1;
                BtData::exact_solution(xi, eta, zeta, u_exact);

                for (m = 0; m < 5; ++m) {
                    add = BtData::u[m][i][j][k] - u_exact[m];
                    rms[m] += add * add;
                }
            }
        }
    }

    for (m = 0; m < 5; ++m) {
        for (d = 0; d < 3; ++d) {
            rms[m] /= static_cast<double>(BtData::grid_points[d] - 2);
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

    for (k = 1; k < BtData::grid_points[2] - 1; ++k) {
        for (j = 1; j < BtData::grid_points[1] - 1; ++j) {
            for (i = 1; i < BtData::grid_points[0] - 1; ++i) {
                for (m = 0; m < 5; ++m) {
                    add = BtData::rhs[m][i][j][k];
                    rms[m] += add * add;
                }
            }
        }
    }

    for (m = 0; m < 5; ++m) {
        for (d = 0; d < 3; ++d) {
            rms[m] /= static_cast<double>(BtData::grid_points[d] - 2);
        }
        rms[m] = std::sqrt(rms[m]);
    }
}
