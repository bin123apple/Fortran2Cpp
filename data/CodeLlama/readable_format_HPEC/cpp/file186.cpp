#include <cmath>
#include <array>

// Assuming bt_data module contents are translated to this structure
struct BTData {
    int grid_points[3];
    double dnxm1, dnym1, dnzm1;
    std::array<std::array<std::array<double, 5>, 2>, 3> u; // 5, 2, 3 dimensions
    std::array<std::array<std::array<double, 5>, 2>, 3> rhs; // 5, 2, 3 dimensions
};

// Function prototypes
void exact_solution(double xi, double eta, double zeta, std::array<double, 5>& u_exact);
void error_norm(const BTData& bt_data, std::array<double, 5>& rms);
void rhs_norm(const BTData& bt_data, std::array<double, 5>& rms);

void error_norm(const BTData& bt_data, std::array<double, 5>& rms) {
    std::fill(rms.begin(), rms.end(), 0.0);

    for (int k = 0; k < bt_data.grid_points[2] - 1; ++k) {
        double zeta = static_cast<double>(k) * bt_data.dnzm1;
        for (int j = 0; j < bt_data.grid_points[1] - 1; ++j) {
            double eta = static_cast<double>(j) * bt_data.dnym1;
            for (int i = 0; i < bt_data.grid_points[0] - 1; ++i) {
                double xi = static_cast<double>(i) * bt_data.dnxm1;
                std::array<double, 5> u_exact;
                exact_solution(xi, eta, zeta, u_exact);

                for (int m = 0; m < 5; ++m) {
                    double add = bt_data.u[m][i][j][k] - u_exact[m];
                    rms[m] += add * add;
                }
            }
        }
    }

    for (int m = 0; m < 5; ++m) {
        for (int d = 0; d < 3; ++d) {
            rms[m] /= static_cast<double>(bt_data.grid_points[d] - 2);
        }
        rms[m] = std::sqrt(rms[m]);
    }
}

void rhs_norm(const BTData& bt_data, std::array<double, 5>& rms) {
    std::fill(rms.begin(), rms.end(), 0.0);

    for (int k = 1; k < bt_data.grid_points[2] - 1; ++k) {
        for (int j = 1; j < bt_data.grid_points[1] - 1; ++j) {
            for (int i = 1; i < bt_data.grid_points[0] - 1; ++i) {
                for (int m = 0; m < 5; ++m) {
                    double add = bt_data.rhs[m][i][j][k];
                    rms[m] += add * add;
                }
            }
        }
    }

    for (int m = 0; m < 5; ++m) {
        for (int d = 0; d < 3; ++d) {
            rms[m] /= static_cast<double>(bt_data.grid_points[d] - 2);
        }
        rms[m] = std::sqrt(rms[m]);
    }
}

// Implementations of exact_solution and other required functions should be provided here
