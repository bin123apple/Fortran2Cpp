#include <cmath>
#include <cstdlib>
#include <iostream>
#include <cassert>

// Declaration of the hcrit function
void hcrit(double xflow, double rho, double b, double theta, double dg, double sqrts0, double& hk);

// Definition of the hcrit function
void hcrit(double xflow, double rho, double b, double theta, double dg, double sqrts0, double& hk) {
    double tth, c1, xflow2, A, dBBdh, dAdh, BB, dhk;

    hk = std::pow((std::pow(xflow / (rho * b), 2) / (dg * sqrts0)), 1.0 / 3.0);

    if (std::abs(theta) < 1e-10) return;

    tth = std::tan(theta);
    c1 = rho * rho * dg * sqrts0;
    xflow2 = xflow * xflow;

    while (true) {
        A = hk * (b + hk * tth);
        dBBdh = 2.0 * tth;
        dAdh = b + hk * dBBdh;
        BB = dAdh;
        dhk = (xflow2 * BB - c1 * std::pow(A, 3)) / (xflow2 * dBBdh - 3.0 * c1 * A * A * dAdh);
        
        if (std::abs(dhk) / dhk < 1e-3) break;
        
        hk = hk - dhk;
    }
}

int main() {
    double xflow = 1.0, rho = 1.0, b = 1.0, theta = 0.1, dg = 1.0, sqrts0 = 1.0, hk;

    // Call the hcrit function
    hcrit(xflow, rho, b, theta, dg, sqrts0, hk);

    std::cout << "hk = " << hk << std::endl;

    // Example of a basic check, in a real case you would want to check against an expected value
    assert(hk > 0); // Assuming hk is expected to be positive for these inputs

    return 0;
}