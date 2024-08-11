#include <iostream>
#include <vector>
#include <cmath>

void EGRID(std::vector<double>& ener, std::vector<double>& del, int nbins) {
    ener.resize(nbins);
    del.resize(nbins);

    for (int n = 0; n < nbins; ++n) {
        if (n + 1 <= 21) {
            ener[n] = 0.5 * static_cast<double>(n + 1);
        } else {
            ener[n] = std::exp(0.05 * static_cast<double>(n + 1 + 26));
        }
    }

    del[0] = 0.5;

    for (int n = 1; n < nbins; ++n) {
        del[n] = ener[n] - ener[n - 1];
    }

    for (int n = 0; n < nbins; ++n) {
        ener[n] = ener[n] - del[n] / 2.0;
    }
}

void testEGRID(int nbins) {
    std::vector<double> ener, del;
    EGRID(ener, del, nbins);

    std::cout << "Testing with " << nbins << " bins..." << std::endl;
    for (int i = 0; i < nbins; ++i) {
        std::cout << "Bin " << i + 1 << ": ENER = " << ener[i] << ", DEL = " << del[i] << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

int main() {
    testEGRID(1);  // Testing small number of bins
    testEGRID(21); // Testing moderate number of bins (boundary condition)
    testEGRID(100); // Testing large number of bins

    return 0;
}