#include <vector>
#include <complex>
#include <cmath>
#include <gtest/gtest.h>

// Define the initialdata function directly in this file
void initialdata(int Nx, int Ny, int Nz, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& z, std::vector<std::vector<std::vector<std::complex<double>>>>& u, std::vector<std::vector<std::vector<std::complex<double>>>>& uold) {
    // Resize the u and uold vectors to match the dimensions Nx, Ny, Nz
    u.resize(Nx);
    uold.resize(Nx);
    for (int i = 0; i < Nx; ++i) {
        u[i].resize(Ny);
        uold[i].resize(Ny);
        for (int j = 0; j < Ny; ++j) {
            u[i][j].resize(Nz);
            uold[i][j].resize(Nz);
        }
    }

    // Initialize u and uold
    #pragma omp parallel for collapse(3) schedule(static)
    for (int k = 0; k < Nz; ++k) {
        for (int j = 0; j < Ny; ++j) {
            for (int i = 0; i < Nx; ++i) {
                u[i][j][k] = 0.5 * std::exp(-1.0 * (std::pow(x[i], 2) + std::pow(y[j], 2) + std::pow(z[k], 2)));
                uold[i][j][k] = u[i][j][k]; // Assuming you want to initialize uold to the same values as u
            }
        }
    }
}

// Unit tests for the initialdata function
TEST(InitialDataTest, TestEquality) {
    int Nx = 10, Ny = 10, Nz = 10;
    std::vector<double> x(Nx), y(Ny), z(Nz);
    for (int i = 0; i < Nx; ++i) {
        x[i] = (i + 1) / 10.0;
        y[i] = (i + 1) / 10.0;
        z[i] = (i + 1) / 10.0;
    }

    std::vector<std::vector<std::vector<std::complex<double>>>> u, uold;
    initialdata(Nx, Ny, Nz, x, y, z, u, uold);

    // Check if u and uold are identical
    for (int k = 0; k < Nz; ++k) {
        for (int j = 0; j < Ny; ++j) {
            for (int i = 0; i < Nx; ++i) {
                EXPECT_EQ(u[i][j][k], uold[i][j][k]);
            }
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}