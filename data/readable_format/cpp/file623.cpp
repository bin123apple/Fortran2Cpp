#include <cmath>

double VP(double T) {
    double TT = T + 273.16;
    return pow(10.0, 22.5518 - (2937.4 / TT) - 4.9283 * log10(TT)) * 10.0;
}