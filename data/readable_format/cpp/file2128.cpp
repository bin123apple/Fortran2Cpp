#include <complex>
#include <vector>
#include <cmath>

void shiftz(const std::vector<std::complex<float>>& spec, int nsp, float dw, std::vector<std::complex<float>>& z) {
    // Ensure the output vector z has the correct size
    z.resize(nsp);

    std::complex<float> multiplier(std::cos(dw), std::sin(dw));

    for (int i = 0; i < nsp; ++i) {
        z[i] = spec[i] * multiplier;
    }
}