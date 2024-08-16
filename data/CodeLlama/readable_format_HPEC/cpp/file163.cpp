#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>

// Assuming ft_data.h or similar provides definitions for fftblock and ilog2
#include "ft_data.h"

// Assuming timer_start, timer_stop are defined elsewhere for timing
// #include "timers.h"

void cfftz(int is, int logd3, int d3, std::vector<std::complex<double>>& y1, std::vector<std::complex<double>>& y2);

void cffts3(int is, int d1, int d2, int d3, std::vector<std::vector<std::vector<std::complex<double>>> >& x, 
            std::vector<std::vector<std::vector<std::complex<double>>> >& xout, 
            std::vector<std::vector<std::complex<double>>>& y1, std::vector<std::vector<std::complex<double>>>& y2) {
    int logd3 = ilog2(d3);

    // Assuming timers_enabled is a global variable or passed in
    if (timers_enabled) timer_start(T_fftz);

    for (int j = 0; j < d2; ++j) {
        for (int in = 0; in < d1 / fftblock - 1; ++in) {
            int ii = in * fftblock;
            for (int k = 0; k < d3; ++k) {
                for (int i = 0; i < fftblock; ++i) {
                    y1[i][k] = x[i + ii][j][k];
                }
            }
        }
    }

    cfftz(is, logd3, d3, y1, y2);

    for (int k = 0; k < d3; ++k) {
        for (int i = 0; i < fftblock; ++i) {
            for (int j = 0; j < d2; ++j) {
                xout[i + ii][j][k] = y1[i][k];
            }
        }
    }

    if (timers_enabled) timer_stop(T_fftz);
}

// The definition of cfftz should be provided elsewhere, as it's not fully defined in the given code.
// It's assumed to be a function that performs the FFT operation based on the parameters.
