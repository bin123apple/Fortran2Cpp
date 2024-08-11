#include <cmath>
#include <iostream>
#include <algorithm>

void cd_ms_ms(double p1, double p2, double T1, double rad, double d, double xl, double kappa, double r, double reynolds, double u, double& vid, double& cd) {
    const double qlim = 10.0;

    cd = 0.5885 + 372.0 / reynolds;
    cd = std::min(cd, 1.0);

    double rzd = rad / d;
    double aux = exp(-(3.5 * rzd + 5.5) * rzd);
    double fakt = aux + 0.008 * (1.0 - aux);
    cd = 1.0 - fakt * (1.0 - cd);
    cd = std::min(std::max(cd, 0.0), 1.0);

    double lkorr = xl - rad;
    double q = lkorr / d;
    double qkorr = std::min(q, qlim);
    fakt = (1.0 + 1.3 * exp(-1.606 * qkorr * qkorr)) * (0.435 + 0.021 * qkorr) / (2.3 * 0.435);
    cd = 1.0 - fakt * (1.0 - cd);
    cd = std::min(std::max(cd, 0.0), 1.0);

    if (u != 0.0) {
        vid = sqrt(2.0 * kappa / (kappa - 1.0) * r * T1 * (1.0 - pow((p2 / p1), (kappa - 1.0) / kappa)));
        double rv = u / vid * pow((0.6 / cd), 3);
        double c1 = exp(-pow(rv, 1.2));
        double c2 = 0.5 * pow(rv, 0.6) * sqrt(0.6 / cd);
        double c3 = exp(-0.5 * pow(rv, 0.9));
        cd = cd * (c1 + c2 * c3);
        cd = std::min(std::max(cd, 0.0), 1.0);
    }
}

int main() {
    double p1 = 101325.0;
    double p2 = 80000.0;
    double T1 = 300.0;
    double rad = 0.5;
    double d = 0.05;
    double xl = 1.0;
    double kappa = 1.4;
    double r = 287.05;
    double reynolds = 100000.0;
    double u = 340.0;
    double vid = 0.0; // Initial value, will be updated by the function
    double cd = 0.0;  // Initial value, will be updated by the function

    cd_ms_ms(p1, p2, T1, rad, d, xl, kappa, r, reynolds, u, vid, cd);

    std::cout << "Test 1: cd = " << cd << std::endl;

    return 0;
}