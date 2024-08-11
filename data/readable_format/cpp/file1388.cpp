#include <cmath>
#include <iostream>
#include <cstdlib>

void tt_calc(double xflow, double& Tt, double pt, double kappa, double r, double A, double Ts, int icase) {
    const double expon = -0.5 * (kappa + 1.0) / (kappa - 1.0);
    const double C = std::sqrt(2.0 / r * kappa / (kappa - 1.0));
    if (std::abs(xflow) <= 1e-9) {
        Tt = Ts;
        return;
    }
    double Qred = std::abs(xflow) * std::sqrt(Ts) / (A * pt);
    Tt = Ts * (1 + (std::pow(Qred, 2) / std::pow(C, 2)));
    double TtzTs_crit;
    if (icase == 0) {
        TtzTs_crit = (kappa + 1.0) / 2.0;
    } else {
        TtzTs_crit = (1.0 + (kappa - 1.0) / (2.0 * kappa));
    }
    if (Tt / Ts > TtzTs_crit) {
        Tt = Ts * (TtzTs_crit + 1.0) / 2.0;
    }
    int i = 0;
    double Tt_old = Tt;
    while (true) {
        i++;
        double Ttzts = Tt / Ts;
        double h1 = Ttzts - 1.0;
        double h2 = std::sqrt(h1);
        double h3 = std::pow(Ttzts, expon);
        double f = C * h2 * h3;
        double df = 0.5 * std::abs(xflow) / (A * pt * std::sqrt(Tt))
            - C * h2 * h3 * (expon / Tt + 1.0 / (2.0 * h1 * Ts));
        Qred = std::abs(xflow) * std::sqrt(Tt) / (A * pt);
        f = Qred - f;
        double deltaTt = -f / df;
        Tt = Tt + deltaTt;
        if ((std::abs(Tt - Tt_old) / Tt_old <= 1e-8) || (std::abs(Tt - Tt_old) <= 1e-10) || ((std::abs(f) <= 1e-5) && (deltaTt < 1e-3))) {
            if (Tt / Ts > TtzTs_crit) {
                Tt = Ts * TtzTs_crit;
            }
            break;
        } else if (i > 40) {
            Tt = 0.99 * Ts * TtzTs_crit;
            break;
        }
        Tt_old = Tt;
    }
}

void test_tt_calc() {
    double xflow = 1.0, Tt = 300.0, pt = 1.0, kappa = 1.4, r = 287.0, A = 1.0, Ts = 288.0;
    int icase = 0;
    tt_calc(xflow, Tt, pt, kappa, r, A, Ts, icase);
    std::cout << "Test 1 - Calculated Tt: " << Tt << std::endl;
    // Ideally, compare Tt to an expected value and report pass/fail based on some tolerance
    // For demonstration, we're simply printing out the result.
}

int main() {
    test_tt_calc();
    return 0;
}