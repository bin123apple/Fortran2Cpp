// EVTS_COWELL.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <array>

// Constants
const double DU = 1.0;
const double TU = 1.0;
const double wEarth = 1.0;
const double smaEarth = 1.0;
const double RSwitch = 1.0;
const double JD_next = 2451545.0;
const double JD_stop = 2451546.0;
const double secsPerDay = 86400.0;

// Assume inSoI is true for this example
const bool inSoI = true;

using ik = int;
using dk = double;
using qk = double;

void QCOWELL_EVT(ik neq, qk t, const std::vector<qk>& y, ik ng, std::vector<qk>& roots) {
    std::array<qk, 3> r_geo, r_Earth;
    qk lon_Earth, rMag;

    if (inSoI) {
        for (int i = 0; i < 3; ++i) {
            r_geo[i] = y[i];
        }
    } else {
        lon_Earth = (wEarth / TU) * t;
        r_Earth = { (smaEarth / DU) * std::cos(lon_Earth), (smaEarth / DU) * std::sin(lon_Earth), 0.0 };
        for (int i = 0; i < 3; ++i) {
            r_geo[i] = y[i] - r_Earth[i];
        }
    }
    rMag = std::sqrt(r_geo[0] * r_geo[0] + r_geo[1] * r_geo[1] + r_geo[2] * r_geo[2]);

    roots[0] = rMag - RSwitch / DU;
}

void DCOWELL_EVT(ik neq, dk t, const std::vector<dk>& y, ik ng, std::vector<dk>& roots) {
    roots[0] = t - JD_next * secsPerDay / TU;
    roots[1] = t - JD_stop * secsPerDay / TU;
}

int main() {
    ik neq = 6, ng = 1;
    qk t_qk = 0.0;
    std::vector<qk> y_qk = {1.0, 1.0, 1.0, 0.0, 0.0, 0.0};
    std::vector<qk> roots_qk(1);

    QCOWELL_EVT(neq, t_qk, y_qk, ng, roots_qk);
    std::cout << "Root (QCOWELL_EVT): " << roots_qk[0] << std::endl;

    neq = 6, ng = 2;
    dk t_dk = 0.0;
    std::vector<dk> y_dk = {1.0, 1.0, 1.0, 0.0, 0.0, 0.0};
    std::vector<dk> roots_dk(2);

    DCOWELL_EVT(neq, t_dk, y_dk, ng, roots_dk);
    std::cout << "Root 1 (DCOWELL_EVT): " << roots_dk[0] << std::endl;
    std::cout << "Root 2 (DCOWELL_EVT): " << roots_dk[1] << std::endl;

    return 0;
}