#include <cmath>

void fcrit(double time, double t, double a, double b, double ze, double d, double dd, 
           double h1, double h2, double h3, double h4, double& func, double& funcp) {
    double fexp = std::exp(-h1 * t);
    func = ((a + b * time) * (-t * h2 - h3) - b * (-t * t * h2 - 2.0 * t * h3 - 2.0 * h4)) * fexp;
    funcp = ((a + b * time) * t - b * (h3 + t * h2 + t * t)) * fexp;
}