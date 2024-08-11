#include <iostream>
#include <vector>
#include <complex>

void zflmconj(int lmax, const std::vector<std::complex<double>>& zflm1, std::vector<std::complex<double>>& zflm2) {
    int lm1, lm2;
    std::complex<double> z1;

    zflm2.resize(zflm1.size());

    for (int l = 0; l <= lmax; ++l) {
        lm1 = l*l;
        lm2 = (l + 1)*(l + 1);
        for (int m = -l; m < 0; ++m) {
            lm1 += 1;
            lm2 -= 1;
            z1 = zflm1[lm1 - 1]; // Adjust for 0-based indexing
            zflm2[lm1 - 1] = std::conj(zflm1[lm2 - 1]);
            zflm2[lm2 - 1] = std::conj(z1);
            if (m % 2 != 0) {
                zflm2[lm1 - 1] = -zflm2[lm1 - 1];
                zflm2[lm2 - 1] = -zflm2[lm2 - 1];
            }
        }
        if (l != 0) {
            lm1 += 1;
            zflm2[lm1 - 1] = std::conj(zflm1[lm1 - 1]); // Adjust for 0-based indexing
        }
    }
}

int main() {
    int lmax = 2;
    std::vector<std::complex<double>> zflm1((lmax+1)*(lmax+1)), zflm2;

    for (size_t i = 0; i < zflm1.size(); ++i) {
        zflm1[i] = std::complex<double>(i+1, i+1);
    }

    zflmconj(lmax, zflm1, zflm2);

    for (size_t i = 0; i < zflm2.size(); ++i) {
        std::cout << "zflm2[" << i << "] = " << zflm2[i] << std::endl;
    }

    return 0;
}