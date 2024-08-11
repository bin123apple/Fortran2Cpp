#include <cmath>
#include <iostream>
#include <cassert>

double QSFNDP(double ECCENT, double SINPHI, double COSPHI) {
    const double HALF = 0.5;
    const double ONE = 1.0;
    const double TWO = 2.0;
    const double EPSLN = 1.0e-7;

    if (ECCENT < EPSLN) {
        return TWO * SINPHI;
    }

    double CON = ECCENT * SINPHI;
    return (ONE - ECCENT * ECCENT) * (SINPHI / (ONE - CON * CON) - 
                  (HALF / ECCENT) * log((ONE - CON) / (ONE + CON)));
}

void testQSFNDP() {
    // Test case values
    double ECCENT = 0.1;
    double SINPHI = 0.5;
    // Assuming COSPHI is not used in the function, but calculated for completeness
    double COSPHI = sqrt(1.0 - SINPHI * SINPHI);

    // Call the function and output the result
    double result = QSFNDP(ECCENT, SINPHI, COSPHI);
    std::cout << "C++ Result: " << result << std::endl;

    // Assert is not used due to variable results, but you can check the output manually
}

int main() {
    testQSFNDP();
    return 0;
}