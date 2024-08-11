#include <iostream>
#include <iomanip> // For setprecision
#include <algorithm> // For min function
#include <cmath> // For pow function

constexpr int kw = 4;
constexpr int kz = 5;

void odrl(int nz, float z[], int nw, float wl[], float c[], float dtrl[][kw]) {
    float srayl, wc, wmicrn, xx;

    for (int iw = 0; iw < nw; ++iw) {
        wc = (wl[iw] + wl[std::min(iw + 1, nw - 1)]) / 2.0f;
        wmicrn = wc / 1000.0f; // Converting to microns
        if (wmicrn <= 0.55f) {
            xx = 3.6772f + 0.389f * wmicrn + 0.09426f / wmicrn;
        } else {
            xx = 4.f + 0.04f;
        }
        srayl = 4.02e-28f / std::pow(wmicrn, xx);
        for (int iz = 0; iz < nz; ++iz) {
            dtrl[iz][iw] = c[iz] * srayl;
        }
    }
}

int main() {
    float z[kz] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float wl[kw] = {0.5, 1.0, 1.5, 2.0};
    float c[kz] = {0.1, 0.2, 0.3, 0.4, 0.5};
    float dtrl[kz][kw] = {0}; // Initialize all elements to zero

    odrl(kz, z, kw, wl, c, dtrl);

    std::cout << std::fixed << std::setprecision(5);
    for (int i = 0; i < kz; i++) {
        std::cout << "dtrl[" << i << ",:] =";
        for (int j = 0; j < kw; j++) {
            std::cout << " " << dtrl[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}