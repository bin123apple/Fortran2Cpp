#include <iostream>
#include <vector>
#include <cmath>

// Namespace to mimic the Fortran module structure, though not strictly necessary in this context
namespace VABPS__genmod {

void VABPS(int MH, int MR, int MP, std::vector<std::vector<std::vector<double>>>& V, double& VEL) {
    double sum = 0.0;
    for (int k = 0; k < MH; ++k) {
        for (int j = 0; j < MR; ++j) {
            for (int i = 0; i < MP; ++i) {
                sum += V[i][j][k];
            }
        }
    }
    VEL = sum / (MP * MR * MH);
}

} // namespace VABPS__genmod

// Function to perform a basic "unit test" on the VABPS function
void testVABPS() {
    using namespace VABPS__genmod;

    int MP = 2, MR = 2, MH = 2;
    std::vector<std::vector<std::vector<double>>> V(MP, std::vector<std::vector<double>>(MR, std::vector<double>(MH, 0)));
    // Initialize V with sample values
    double values[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    int index = 0;
    for (int i = 0; i < MP; ++i) {
        for (int j = 0; j < MR; ++j) {
            for (int k = 0; k < MH; ++k) {
                V[i][j][k] = values[index++];
            }
        }
    }

    double VEL;
    VABPS(MH, MR, MP, V, VEL);

    std::cout << "Computed VEL: " << VEL << std::endl;
    if (std::fabs(VEL - 4.5) < 0.00001) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }
}

int main() {
    testVABPS();
    return 0;
}