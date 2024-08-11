#include <iostream>
#include <cmath>
#include <algorithm>

// Function declaration
void cd_ms_ms(double& p1, double& p2, double& T1, double& rad, double& d, double& xl, double& kappa, double& r, double& reynolds, double& u, double& vid, double& cd) {
    double qlim = 10.0;
    double q;
    double c1, c2, c3, fakt, aux, rzd, lkorr, qkorr, rv;

    cd = 0.5885 + 372.0 / reynolds;
    cd = std::min(cd, 1.0);

    rzd = rad / d;
    aux = std::exp(-(3.5 * rzd + 5.5) * rzd);
    fakt = aux + 0.008 * (1.0 - aux);
    cd = 1.0 - fakt * (1.0 - cd);
    cd = std::min(std::max(cd, 0.0), 1.0);

    lkorr = xl - rad;
    q = lkorr / d;
    qkorr = std::min(q, qlim);
    fakt = (1.0 + 1.3 * std::exp(-1.606 * std::pow(qkorr, 2.0))) *
           (0.435 + 0.021 * qkorr) / (2.3 * 0.435);
    cd = 1.0 - fakt * (1.0 - cd);
    cd = std::min(std::max(cd, 0.0), 1.0);

    if(u != 0.0) {
        vid = std::sqrt(2.0 * kappa / (kappa - 1.0) * r * T1 *
              (1.0 - std::pow((p2 / p1), (kappa - 1.0) / kappa)));
        rv = u / vid * std::pow((0.6 / cd), 3);
        c1 = std::exp(-std::pow(rv, 1.2));
        c2 = 0.5 * std::pow(rv, 0.6) * std::sqrt(0.6 / cd);
        c3 = std::exp(-0.5 * std::pow(rv, 0.9));
        cd = cd * (c1 + c2 * c3);
        cd = std::min(std::max(cd, 0.0), 1.0);
    }
}

// Main function to demonstrate usage and testing
int main() {
    // Test parameters
    double p1 = 101325.0;
    double p2 = 100000.0;
    double T1 = 300.0;
    double rad = 0.5;
    double d = 1.0;
    double xl = 1.0;
    double kappa = 1.4;
    double r = 287.0;
    double reynolds = 10000.0;
    double u = 50.0;
    double vid; // Output parameter
    double cd;  // Output parameter

    // Calling the function
    cd_ms_ms(p1, p2, T1, rad, d, xl, kappa, r, reynolds, u, vid, cd);

    // Simple test output
    std::cout << "Calculated CD: " << cd << std::endl;

    // Add more tests as needed

    return 0;
}