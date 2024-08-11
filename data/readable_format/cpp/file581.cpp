#include <cmath> // For std::abs

double SHConfidence(int l_conf, double r) {
    double prod = 1.0;
    double SHConfidence = std::abs(r);

    for (int l = 2; l <= l_conf; ++l) {
        int i = l - 1;
        prod *= static_cast<double>(2*i - 1) / static_cast<double>(2*i);
        SHConfidence += prod * std::abs(r) * std::pow(1.0 - r*r, l-1);
    }

    return SHConfidence;
}