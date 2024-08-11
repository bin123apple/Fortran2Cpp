#include <iostream>
#include <cmath>
#include <cassert>

void x_pbe(double kappa, double mu, double rho, double s, double u, double v, double& ex, double& vx) {
    const double ax = -0.7385587663820224058;
    const double thrd = 1.0 / 3.0;
    const double thrd4 = 4.0 / 3.0;

    double ul = mu / kappa;
    double exu = ax * std::pow(rho, thrd);
    double s2 = s * s;
    double p0 = 1.0 + ul * s2;
    double fxpbe = 1.0 + kappa - kappa / p0;
    ex = exu * fxpbe;
    double fs = 2.0 * kappa * ul / (p0 * p0);
    double fss = -4.0 * ul * s * fs / p0;
    vx = exu * (thrd4 * fxpbe - (u - thrd4 * s2 * s) * fss - v * fs);
}

int main() {
    double kappa = 0.5;
    double mu = 0.3;
    double rho = 1.0;
    double s = 0.2;
    double u = 0.1;
    double v = 0.05;
    double ex, vx;

    x_pbe(kappa, mu, rho, s, u, v, ex, vx);

    std::cout << "C++ ex = " << ex << std::endl;
    std::cout << "C++ vx = " << vx << std::endl;

    // No assertions here, as values to be compared visually with Fortran output for consistency
    return 0;
}