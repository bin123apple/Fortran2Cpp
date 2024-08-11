#include <cmath>

float db(float x) {
    if (x > 1.259e-10) {
        return 10.0 * log10(x);
    } else {
        return -99.0;
    }
}