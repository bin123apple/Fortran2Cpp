#include <iostream>
#include <cmath>

// Function prototype is optional in this case since definition is before use
// double funden(double SAL, double SED, double TEM);

// Function definition
double funden(double SAL, double SED, double TEM) {
    double SSG = 2.5;
    double SDEN = 1.0 / 2500000.0;
    double SSTMP = SAL;
    double TTMP = TEM;
    double RHTMP = 999.842594 + 6.793952E-2 * TTMP - 9.095290E-3 * TTMP * TTMP
                 + 1.001685E-4 * TTMP * TTMP * TTMP - 1.120083E-6 * TTMP * TTMP * TTMP * TTMP
                 + 6.536332E-9 * TTMP * TTMP * TTMP * TTMP * TTMP;
    double RHO = RHTMP + SSTMP * (0.824493 - 4.0899E-3 * TTMP + 7.6438E-5 * TTMP * TTMP
                 - 8.2467E-7 * TTMP * TTMP * TTMP + 5.3875E-9 * TTMP * TTMP * TTMP * TTMP)
                 + sqrt(SSTMP) * SSTMP * (-5.72466E-3 + 1.0227E-4 * TTMP
                 - 1.6546E-6 * TTMP * TTMP) + 4.8314E-4 * SSTMP * SSTMP;
    RHO = RHO * ((1.0 - SDEN * SED) + (SSG - 1.0) * SDEN * SED);

    return RHO;
}

// Test code
int main() {
    double SAL = 35.0;  // Example salinity
    double SED = 1.5;   // Example sediment
    double TEM = 15.0;  // Example temperature
    double result = funden(SAL, SED, TEM);

    std::cout << "Testing FUNDEN with SAL=" << SAL << ", SED=" << SED << ", TEM=" << TEM << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}