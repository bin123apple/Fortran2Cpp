#include <iostream>
#include <cmath>

void ALIGNP(double& CFX, double& CFY, double& CFZ, double& FXP, double& FYP, double& FZP, 
            double AKX1, double AKX2, double AKX3, double AKX4, 
            double AKY1, double AKY2, double AKY3, double AKY4, 
            double AKZ1, double AKZ2, double AKZ3, double AKZ4, double DTSC) {
    FXP = FXP - DTSC * AKX4;
    FYP = FYP - DTSC * AKY4;
    FZP = FZP - DTSC * AKZ4;

    CFX = AKX1 * FXP + AKX2 * FYP + AKX3 * FZP;
    CFY = AKY1 * FXP + AKY2 * FYP + AKY3 * FZP;
    CFZ = AKZ1 * FXP + AKZ2 * FYP + AKZ3 * FZP;

    FXP = 0.0;
    FYP = 0.0;
    FZP = 0.0;
}

int main() {
    double CFX, CFY, CFZ;
    double FXP = 1.0, FYP = 2.0, FZP = 3.0;
    double AKX1 = 0.1, AKX2 = 0.2, AKX3 = 0.3, AKX4 = 0.4;
    double AKY1 = 0.5, AKY2 = 0.6, AKY3 = 0.7, AKY4 = 0.8;
    double AKZ1 = 0.9, AKZ2 = 1.0, AKZ3 = 1.1, AKZ4 = 1.2;
    double DTSC = 0.01;

    ALIGNP(CFX, CFY, CFZ, FXP, FYP, FZP, AKX1, AKX2, AKX3, AKX4, AKY1, AKY2, AKY3, AKY4, AKZ1, AKZ2, AKZ3, AKZ4, DTSC);

    std::cout << "CFX: " << CFX << ", CFY: " << CFY << ", CFZ: " << CFZ << std::endl;

    return 0;
}