// File: DPHYBRID.cpp
#include <cmath>
#include <iostream>
#include <vector>
#include <cassert>

void DPHYBRIDJRA55(const std::vector<double>& HYA, const std::vector<double>& HYB, const std::vector<std::vector<double>>& PSFC, int MLON, int NLAT, int KLEV, std::vector<std::vector<std::vector<double>>>& PHY, double PMSG, int KLEVI) {
    std::vector<std::vector<std::vector<double>>> PI(MLON, std::vector<std::vector<double>>(NLAT, std::vector<double>(KLEVI)));
    
    for (int KL = 0; KL < KLEVI; ++KL) {
        for (int NL = 0; NL < NLAT; ++NL) {
            for (int ML = 0; ML < MLON; ++ML) {
                if (PSFC[ML][NL] != PMSG) {
                    PI[ML][NL][KL] = HYA[KL] + HYB[KL] * PSFC[ML][NL];
                } else {
                    PI[ML][NL][KL] = PMSG;
                }
            }
        }
    }

    for (int NL = 0; NL < NLAT; ++NL) {
        for (int ML = 0; ML < MLON; ++ML) {
            for (int KL = 0; KL < KLEV; ++KL) {
                if (PSFC[ML][NL] != PMSG) {
                    double DP = PI[ML][NL][KL] - PI[ML][NL][KL + 1];
                    PHY[ML][NL][KL] = std::exp((1 / DP) * (PI[ML][NL][KL] * std::log(PI[ML][NL][KL]) - PI[ML][NL][KL + 1] * std::log(PI[ML][NL][KL + 1])) - 1);
                } else {
                    PHY[ML][NL][KL] = PMSG;
                }
            }
        }
    }
    
    for (int NL = 0; NL < NLAT; ++NL) {
        for (int ML = 0; ML < MLON; ++ML) {
            PHY[ML][NL][KLEV - 1] = 10.0; // Ensure the last level is set as specified
        }
    }
}

int main() {
    int MLON = 2, NLAT = 2, KLEV = 2, KLEVI = 3;
    std::vector<double> HYA = {1.0, 2.0, 3.0};
    std::vector<double> HYB = {0.5, 0.25, 0.125};
    std::vector<std::vector<double>> PSFC = {{1000.0, 2000.0}, {1500.0, 1000.0}};
    double PMSG = 9999.0;
    std::vector<std::vector<std::vector<double>>> PHY(MLON, std::vector<std::vector<double>>(NLAT, std::vector<double>(KLEV)));

    DPHYBRIDJRA55(HYA, HYB, PSFC, MLON, NLAT, KLEV, PHY, PMSG, KLEVI);

    // Example check
    std::cout << "PHY Array Check:" << std::endl;
    for (int KL = 0; KL < KLEV; ++KL) {
        std::cout << "Level " << KL + 1 << std::endl;
        for (int NL = 0; NL < NLAT; ++NL) {
            for (int ML = 0; ML < MLON; ++ML) {
                std::cout << PHY[ML][NL][KL] << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}