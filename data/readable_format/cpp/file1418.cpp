#include <cmath>

bool SIDEP(double ANGLE) {
    const double EPS = 1.27;
    const double PI = atan2(0.0, -1.0);

    if ((ANGLE > (PI - EPS)) && (ANGLE < (PI + EPS))) {
        return true;
    } else {
        return false;
    }
}