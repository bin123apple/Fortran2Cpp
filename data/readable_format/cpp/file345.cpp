#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

// Translated fbar function
complex<double> fbar(complex<double> P) {
    const double TOSP = 1.128379167;
    const double ACCS = 1.E-12;
    const double SP = 1.772453851;
    complex<double> FJ[2] = {complex<double>(0.0, 0.0), complex<double>(1.0, 0.0)};
    complex<double> Z = FJ[1] * sqrt(P);
    complex<double> ZS, SUM, POW, TERM;
    double TMS, SMS;

    if (abs(Z) > 3.0) {
        bool minus = false;
        if (real(Z) < 0.0) {
            minus = true;
            Z = -Z;
        }
        ZS = 0.5 / (Z * Z);
        SUM = complex<double>(0.0, 0.0);
        TERM = complex<double>(1.0, 0.0);

        for (int I = 1; I <= 6; ++I) {
            TERM = -TERM * (2.0 * static_cast<double>(I) - 1.0) * ZS;
            SUM += TERM;
        }
        if (minus) {
            SUM = SUM - 2.0 * SP * Z * exp(Z * Z);
        }
        return -SUM;
    } else {
        ZS = Z * Z;
        SUM = Z;
        POW = Z;
        for (int I = 1; I <= 100; ++I) {
            POW = -POW * ZS / static_cast<double>(I);
            TERM = POW / (2.0 * static_cast<double>(I) + 1.0);
            SUM += TERM;
            TMS = norm(TERM);
            SMS = norm(SUM);
            if (TMS / SMS < ACCS) {
                break;
            }
        }
        return 1.0 - (1.0 - SUM * TOSP) * Z * exp(ZS) * SP;
    }
}

void testFbar(complex<double> arg, const string& testName) {
    complex<double> result = fbar(arg);
    cout << testName << ": fbar(" << arg << ") = " << result << endl;
}

int main() {
    testFbar(complex<double>(1.0, 1.0), "Test 1");
    testFbar(complex<double>(2.0, -1.0), "Test 2");
    testFbar(complex<double>(-2.0, 2.0), "Test 3");
    testFbar(complex<double>(0.5, 0.5), "Test 4");

    return 0;
}