#include <iostream>
#include <cmath>

const int nLons = 2, nLats = 2, nAlts = 2;
double eTemperature[nLons][nLats][nAlts];
double Temperature[nLons][nLats][nAlts];
double TempUnit[nLons][nLats][nAlts];
double Altitude_GB[nLons][nLats][nAlts] = {{{1000.0, 1500.0}, {2000.0, 2500.0}}, {{3000.0, 3500.0}, {4000.0, 8000.0}}};

void calc_electron_temperature(int iBlock) {
    for (int iLon = 0; iLon < nLons; ++iLon) {
        for (int iLat = 0; iLat < nLats; ++iLat) {
            for (int iAlt = 0; iAlt < nAlts; ++iAlt) {
                double Alt = Altitude_GB[iLon][iLat][iAlt] / 1000.0;
                if (Alt < 130.0) {
                    eTemperature[iLon][iLat][iAlt] = Temperature[iLon][iLat][iAlt] * TempUnit[iLon][iLat][iAlt];
                } else {
                    eTemperature[iLon][iLat][iAlt] = 0.0;
                }
            }
        }
    }
}

int main() {
    int iBlock = 1;
    for (int i = 0; i < nLons; ++i) {
        for (int j = 0; j < nLats; ++j) {
            for (int k = 0; k < nAlts; ++k) {
                Temperature[i][j][k] = 20.0;
                TempUnit[i][j][k] = 1.0;
            }
        }
    }

    calc_electron_temperature(iBlock);

    std::cout << "C++ eTemperature:" << std::endl;
    for (int i = 0; i < nLons; ++i) {
        for (int j = 0; j < nLats; ++j) {
            for (int k = 0; k < nAlts; ++k) {
                std::cout << eTemperature[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}