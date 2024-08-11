#include <iostream>
#include <array>
#include <cmath>
#include <iomanip>

// Define the PYGDIR function directly in this file
void PYGDIR(double X, double Q2, double P2, double Q02, std::array<double, 13>& XPGA) {
    const double PMC = 1.3; // Assuming D0 is double precision
    const double PMB = 4.6;
    const double AEM2PI = 0.0011614;

    for (int KFL = 0; KFL <= 12; ++KFL) {
        XPGA[KFL] = 0.0;
    }

    double XTMP = (std::pow(X, 2) + std::pow((1.0 - X), 2)) * (-std::log(X)) - 1.0;
    double CGAM = 3.0 * AEM2PI * X * (XTMP * (1.0 + P2 / (P2 + Q02)) + 6.0 * X * (1.0 - X));

    XPGA[6+1] = (1.0 / 9.0) * CGAM;
    XPGA[6+2] = (4.0 / 9.0) * CGAM;
    XPGA[6+3] = (1.0 / 9.0) * CGAM;

    for (int KF = 1; KF <= 5; ++KF) {
        XPGA[6-KF] = XPGA[6+KF];
    }
}

// Test function for PYGDIR
void TestPYGDIR() {
    std::array<double, 13> XPGA;
    PYGDIR(0.5, 1.0, 1.0, 1.0, XPGA);

    std::cout << "Testing PYGDIR..." << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    for(int i = -6; i <= 6; ++i) {
        std::cout << "XPGA[" << i << "] = " << XPGA[i + 6] << std::endl;
    }
    std::cout << "All tests done." << std::endl;
}

int main() {
    TestPYGDIR();
    return 0;
}