#include <iostream>
#include <cmath>
#include <algorithm>

// Function Declaration
void sla_REFCOQ(double TDK, double PMB, double RH, double WL, double& REFA, double& REFB);

// Main Function - Tests included here
int main() {
    double REFA, REFB;
    
    // Test 1
    sla_REFCOQ(293.15, 1013.25, 0.5, 0.7, REFA, REFB);
    std::cout << "Test 1 - REFA: " << REFA << ", REFB: " << REFB << std::endl;
    
    // Additional tests can go here

    return 0;
}

// Function Definition
void sla_REFCOQ(double TDK, double PMB, double RH, double WL, double& REFA, double& REFB) {
    bool OPTIC = WL <= 100.0;
    double T = std::min(std::max(TDK, 100.0), 500.0);
    double P = std::min(std::max(PMB, 0.0), 10000.0);
    double R = std::min(std::max(RH, 0.0), 1.0);
    double W = std::min(std::max(WL, 0.1), 1e6);

    double TDC, PS, PW, WLSQ, GAMMA, BETA;

    if (P > 0.0) {
        TDC = T - 273.15;
        PS = std::pow(10.0, (0.7859 + 0.03477 * TDC) / (1.0 + 0.00412 * TDC)) * (1.0 + P * (4.5e-6 + 6e-10 * TDC * TDC));
        PW = R * PS / (1.0 - (1.0 - R) * PS / P);
    } else {
        PW = 0.0;
    }

    if (OPTIC) {
        WLSQ = W * W;
        GAMMA = ((77.53484e-6 + (4.39108e-7 + 3.666e-9 / WLSQ) / WLSQ) * P - 11.2684e-6 * PW) / T;
    } else {
        GAMMA = (77.6890e-6 * P - (6.3938e-6 - 0.375463 / T) * PW) / T;
    }

    BETA = 4.4474e-6 * T;
    if (!OPTIC) BETA -= 0.0074 * PW * BETA;

    REFA = GAMMA * (1.0 - BETA);
    REFB = -GAMMA * (BETA - GAMMA / 2.0);
}