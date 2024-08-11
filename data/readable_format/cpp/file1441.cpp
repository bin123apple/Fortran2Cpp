#include <iostream>
#include <cmath>
#include <cassert>

// Define the ts_calc function
void ts_calc(double xflow, double Tt, double Pt, double kappa, double r, double a, double& Ts, int icase) {
    const double expon = -0.5 * (kappa + 1.0) / (kappa - 1.0);
    const double C = sqrt(2.0 / r * kappa / (kappa - 1.0));
    double Ts_old = Tt;
    int inv = (xflow < 0.0) ? -1 : 1;

    if(std::abs(xflow) <= 1e-9) {
        Ts = Tt;
        return;
    }

    double Qred = std::abs(xflow) * sqrt(Tt) / (a * Pt);
    Ts = Tt / (1 + (Qred * Qred / (C * C)));

    double TtzTs_crit;
    if(icase == 0) {
        TtzTs_crit = (kappa + 1.0) / 2.0;
    } else {
        TtzTs_crit = 1.0 + (kappa - 1.0) / (2.0 * kappa);
    }

    double Qred_crit = C * std::pow(TtzTs_crit, expon) * sqrt(TtzTs_crit - 1.0);
    if(Qred >= Qred_crit) {
        Ts = Tt / TtzTs_crit;
        return;
    }

    int i = 0;
    do {
        i++;
        double TtzTs = Tt / Ts;
        double h1 = TtzTs - 1.0;
        double h2 = sqrt(h1);
        double h3 = pow(TtzTs, expon);
        double f = C * h2 * h3;
        double df = f * (expon + 0.5 * TtzTs / h1) / Ts;
        f = Qred - f;
        double deltaTs = -f / df;
        Ts = Ts + deltaTs;

        if ((std::abs(Ts - Ts_old) / Ts_old <= 1E-8) || (std::abs(Ts - Ts_old) <= 1E-10)) {
            break;
        } else if (i > 20) {
            Ts = 0.9 * Tt;
            break;
        }

        Ts_old = Ts;
    } while (true);
}

// Main function to test the ts_calc function
int main() {
    double xflow = 0.5;
    double Tt = 300.0;
    double Pt = 101325.0;
    double kappa = 1.4;
    double r = 287.0;
    double a = 340.29;
    int icase = 0;
    double Ts = 0.0;

    // Call the function
    ts_calc(xflow, Tt, Pt, kappa, r, a, Ts, icase);

    // Output the result
    std::cout << "Ts = " << Ts << std::endl;

    // Basic assertion to ensure Ts was calculated
    assert(Ts != 0.0);

    return 0;
}