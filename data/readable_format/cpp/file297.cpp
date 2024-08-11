#include <cmath> // Include the cmath header for math functions

// Translate exau function
double exau(double x, double y, double t) {
    return -exp(-2 * t) * cos(x) * sin(y);
}

// Translate exav function
double exav(double x, double y, double t) {
    return exp(-2 * t) * sin(x) * cos(y);
}

// Translate exap function
double exap(double x, double y, double t) {
    return -0.25 * exp(-4 * t) * (cos(2 * x) + cos(2 * y));
}