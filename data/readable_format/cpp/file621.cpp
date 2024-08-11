#include <cmath> // For std::abs

void cdiv(double ar, double ai, double br, double bi, double& cr, double& ci) {
    double s_inv, ars, ais, brs, bis;
    s_inv = 1.0 / ( std::abs(br) + std::abs(bi) );
    ars = ar * s_inv;
    ais = ai * s_inv;
    brs = br * s_inv;
    bis = bi * s_inv;
    s_inv = 1.0 / ( brs*brs + bis*bis );
    cr = (ars*brs + ais*bis) * s_inv;
    ci = (ais*brs - ars*bis) * s_inv;
}