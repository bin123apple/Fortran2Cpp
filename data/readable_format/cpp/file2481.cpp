#include <cmath>

double iau_ANP(double A) {
    const double D2PI = 6.283185307179586476925287;
    double W = fmod(A, D2PI);
    if (W < 0.0) {
        W += D2PI;
    }
    return W;
}