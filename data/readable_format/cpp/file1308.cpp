#include <iostream>
#include <cassert>
#include <cmath> // For sqrt, pow, and fabs functions

void appmth(float runoff, float remax, float efflen, float ealpha, float m, float effdrr, float& peakro) {
    float tc;
    float te, vave, tstar, vstar, qpstar, a, b, c;

    if (runoff < 0.00000001f) {
        peakro = 0;
        return;
    }

    vave = runoff / effdrr;
    te = std::pow((efflen / (ealpha * std::pow(vave, m - 1.0f))), (1.0f / m));
    tstar = te / effdrr;
    vstar = vave / remax;

    if (tstar >= 1.0f) {
        qpstar = 1.0f / std::pow(tstar, m);
    } else {
        if (vstar < 1.0f) {
            a = 0.6f * (1.0f - vstar);
            b = -1.0f;
            c = vstar;
            tc = (-b - std::sqrt(b * b - 4.0f * a * c)) / (2.0f * a);

            if (tstar > tc) {
                qpstar = 1.0f / tstar;
            } else {
                qpstar = 1.0f / vstar - 0.6f * (1.0f - vstar) / vstar * tstar;
            }
        } else {
            qpstar = 1.0f;
        }
    }

    peakro = vave * qpstar;
}

int main() {
    float runoff = 0.5f;
    float remax = 1.0f;
    float efflen = 100.0f;
    float ealpha = 0.2f;
    float m = 0.5f;
    float effdrr = 10.0f;
    float peakro;

    appmth(runoff, remax, efflen, ealpha, m, effdrr, peakro);
    std::cout << "C++ Test: Peak Runoff = " << peakro << std::endl;

    // Example assertion based on expected value from Fortran output for this test case
    // Adjust the expected value based on your Fortran program's output
    assert(std::fabs(peakro - 0.00141421368) < 0.0001);

    std::cout << "All tests passed." << std::endl;
    return 0;
}