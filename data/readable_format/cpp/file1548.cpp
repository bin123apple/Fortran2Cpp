#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

// Define the COMPRO function directly, without using a class
void COMPRO(std::vector<double>& PROFILE, const std::vector<double>& EMINT, int NFOBR, double W, int JFIRST, int JLAST) {
    for (int K = 0; K < NFOBR; ++K) {
        if (JFIRST == JLAST) {
            PROFILE[K] = EMINT[K];
        } else {
            PROFILE[K] = PROFILE[K] + W * EMINT[K];
        }
    }
}

int main() {
    std::vector<double> profile = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> emint = {0.5, 1.5, 2.5, 3.5, 4.5};
    double w = 0.5;
    int jfirst = 1, jlast = 5;
    int NFOBR = 5;

    // Call the function
    COMPRO(profile, emint, NFOBR, w, jfirst, jlast);

    // Expected results based on the original Fortran logic
    std::vector<double> expected = {1.25, 2.75, 4.25, 5.75, 7.25};

    // Assert results
    for (int i = 0; i < NFOBR; ++i) {
        assert(std::fabs(profile[i] - expected[i]) < 1e-9); // Floating-point comparison
    }

    std::cout << "C++ test passed." << std::endl;

    return 0;
}