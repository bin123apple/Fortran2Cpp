#include <cmath>

const double D2R = 0.017453292519943;

void hlugProj(double phi0, double lambda0, double phi, double lambda, double& x, double& y) {
    double sin0, cos0, sinp, cosp, sind, cosd, denom;

    sin0 = std::sin(D2R * phi0);
    cos0 = std::cos(D2R * phi0);
    sinp = std::sin(D2R * phi);
    cosp = std::cos(D2R * phi);
    sind = std::sin(D2R * (lambda - lambda0));
    cosd = std::cos(D2R * (lambda - lambda0));
    
    denom = sin0 * sinp + cos0 * cosp * cosd;
    
    x = (cosp * sind) / denom;
    y = (cos0 * sinp - sin0 * cosp * cosd) / denom;
}