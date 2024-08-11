#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cassert>

void tt_calc(double xflow, double& Tt, double Pt, double kappa, double r, double A, double Ts, int icase) {
    double expon = -0.5 * (kappa + 1.0) / (kappa - 1.0);
    double C = std::sqrt(2.0 / r * kappa / (kappa - 1.0));
    if(std::abs(xflow) <= 1e-9) {
        Tt = Ts;
        return;
    }
    double Qred = std::abs(xflow) * std::sqrt(Ts) / (A * Pt);
    Tt = Ts * (1 + (Qred * Qred / (C * C)));
    double TtzTs_crit;
    if(icase == 0) {
        TtzTs_crit = (kappa + 1.0) / 2.0;
    } else {
        TtzTs_crit = (1.0 + (kappa - 1.0) / (2.0 * kappa));
    }
    if(Tt / Ts > TtzTs_crit) {
        Tt = Ts * (TtzTs_crit + 1.0) / 2.0;
    }
    int i = 0;
    double Tt_old = Tt;
    do {
        ++i;
        double TtzTs = Tt / Ts;
        double h1 = TtzTs - 1.0;
        double h2 = std::sqrt(h1);
        double h3 = std::pow(TtzTs, expon);
        double f = C * h2 * h3;
        double df = 0.5 * std::abs(xflow) / (A * Pt * std::sqrt(Tt))
                   - C * h2 * h3 * (expon / Tt + 1.0 / (2.0 * h1 * Ts));
        Qred = std::abs(xflow) * std::sqrt(Tt) / (A * Pt);
        f = Qred - f;
        double deltaTt = -f / df;
        Tt += deltaTt;
        if ((std::abs(Tt - Tt_old) / Tt_old <= 1.E-8) ||
            (std::abs(Tt - Tt_old) <= 1.E-10) ||
            (std::abs(f) <= 1E-5 && deltaTt < 1E-3)) {
            if (Tt / Ts > TtzTs_crit) {
                Tt = Ts * TtzTs_crit;
            }
            break;
        } else if (i > 40) {
            Tt = 0.99 * Ts * TtzTs_crit;
            break;
        }
        Tt_old = Tt;
    } while (true);
}

void test_tt_calc() {
    double xflow = 0.02;
    double Tt;
    double Pt = 1.0;
    double kappa = 1.4;
    double r = 287.0;
    double A = 1.0;
    double Ts = 300;
    int icase = 0;

    tt_calc(xflow, Tt, Pt, kappa, r, A, Ts, icase);

    std::cout << "C++ Test Case - Tt: " << Tt << std::endl;
}

int main() {
    test_tt_calc();
    return 0;
}