#include <iostream>
#include <array>

// Definition of norshell8 directly in this file
void norshell8(double xi, double et, const std::array<std::array<double, 8>, 3>& xl, std::array<double, 3>& xnor) {
    std::array<std::array<double, 8>, 4> shp{};
    std::array<std::array<double, 2>, 3> xs{};

    // Calculate shape functions
    shp[0][0] = (1.0 - et) * (2.0 * xi + et) / 4.0;
    shp[0][1] = (1.0 - et) * (2.0 * xi - et) / 4.0;
    shp[0][2] = (1.0 + et) * (2.0 * xi + et) / 4.0;
    shp[0][3] = (1.0 + et) * (2.0 * xi - et) / 4.0;
    shp[0][4] = -xi * (1.0 - et);
    shp[0][5] = (1.0 - et * et) / 2.0;
    shp[0][6] = -xi * (1.0 + et);
    shp[0][7] = -(1.0 - et * et) / 2.0;

    shp[1][0] = (1.0 - xi) * (2.0 * et + xi) / 4.0;
    shp[1][1] = (1.0 + xi) * (2.0 * et - xi) / 4.0;
    shp[1][2] = (1.0 + xi) * (2.0 * et + xi) / 4.0;
    shp[1][3] = (1.0 - xi) * (2.0 * et - xi) / 4.0;
    shp[1][4] = -(1.0 - xi * xi) / 2.0;
    shp[1][5] = -et * (1.0 + xi);
    shp[1][6] = (1.0 - xi * xi) / 2.0;
    shp[1][7] = -et * (1.0 - xi);

    // Compute xs
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            xs[i][j] = 0.0;
            for (int k = 0; k < 8; ++k) {
                xs[i][j] += xl[i][k] * shp[j][k];
            }
        }
    }

    // Compute normal vector
    xnor[0] = xs[1][0] * xs[2][1] - xs[2][0] * xs[1][1];
    xnor[1] = xs[0][1] * xs[2][0] - xs[2][1] * xs[0][0];
    xnor[2] = xs[0][0] * xs[1][1] - xs[1][0] * xs[0][1];
}

int main() {
    double xi = 0.5;
    double et = -0.25;
    std::array<std::array<double, 8>, 3> xl{{{{1, 2, 3, 4, 5, 6, 7, 8}}, {{9, 10, 11, 12, 13, 14, 15, 16}}, {{17, 18, 19, 20, 21, 22, 23, 24}}}};
    std::array<double, 3> xnor;

    // Call the function
    norshell8(xi, et, xl, xnor);

    // Print the result to compare
    std::cout << "xnor:" << std::endl;
    for (const auto& comp : xnor) {
        std::cout << comp << std::endl;
    }

    return 0;
}