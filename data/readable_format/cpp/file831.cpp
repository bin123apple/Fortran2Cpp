#include <iostream>
#include <cmath>

void DMIXHUM1(double P, double TK, double RH, int ISWIT, double& QW) {
    const double T0 = 273.15;
    const double EP = 0.622;
    const double ONEMEP = 0.378;
    const double ES0 = 6.11;
    const double A = 17.269;
    const double B = 35.86;

    double EST = ES0 * exp((A * (TK - T0)) / (TK - B));
    double QST = (EP * EST) / (P - ONEMEP * EST);
    QW = QST * (RH * 0.01);

    if (abs(ISWIT) == 2) {
        QW = QW / (1.0 + QW);
    }
    if (ISWIT < 0) {
        QW = QW * 1000.0;
    }
}

int main() {
    double P, TK, RH, QW;
    int ISWIT;

    // Test 1
    P = 1013.25; TK = 298.15; RH = 50.0; ISWIT = 1;
    DMIXHUM1(P, TK, RH, ISWIT, QW);
    std::cout << "Test 1: QW=" << QW << std::endl;

    // Test 2
    P = 1013.25; TK = 200.0; RH = 10.0; ISWIT = -1;
    DMIXHUM1(P, TK, RH, ISWIT, QW);
    std::cout << "Test 2: QW=" << QW << std::endl;

    return 0;
}