#include <iostream>
#include <vector>
#include <cassert>

// Function to set auxiliary grid data
void clawpack46SetAux(int mbc, int mx, int my, int mz,
                      double xlower, double ylower, double zlower,
                      double dx, double dy, double dz,
                      int maux,
                      std::vector<std::vector<std::vector<std::vector<double>>>>& aux) {
    aux.resize(mx + 2 * mbc);
    for (int i = 0; i < mx + 2 * mbc; ++i) {
        aux[i].resize(my + 2 * mbc);
        for (int j = 0; j < my + 2 * mbc; ++j) {
            aux[i][j].resize(mz + 2 * mbc);
            for (int k = 0; k < mz + 2 * mbc; ++k) {
                aux[i][j][k].resize(maux);
                // Example initialization
                for (int l = 0; l < maux; ++l) {
                    aux[i][j][k][l] = (i + j + k + l); // Simple value assignment for demonstration
                }
            }
        }
    }
}

// Test function
void test_clawpack46SetAux() {
    int mbc = 1, mx = 2, my = 2, mz = 2, maux = 3;
    double xlower = 0.0, ylower = 0.0, zlower = 0.0, dx = 1.0, dy = 1.0, dz = 1.0;
    std::vector<std::vector<std::vector<std::vector<double>>>> aux;

    clawpack46SetAux(mbc, mx, my, mz, xlower, ylower, zlower, dx, dy, dz, maux, aux);

    // Basic test to verify the dimensions of the 'aux' array
    assert(aux.size() == mx + 2 * mbc);
    for (const auto& dim1 : aux) {
        assert(dim1.size() == my + 2 * mbc);
        for (const auto& dim2 : dim1) {
            assert(dim2.size() == mz + 2 * mbc);
            for (const auto& dim3 : dim2) {
                assert(dim3.size() == maux);
            }
        }
    }

    std::cout << "Test passed: All dimensions are correct." << std::endl;

    // Add more tests as needed
}

int main() {
    test_clawpack46SetAux();
    // You can add more test cases or other functionality here
    return 0;
}