#include <complex>
#include <cmath>

// Assuming the existence of a similar "ft_data" module in C++
// which might contain necessary definitions or declarations.
#include "ft_data.h"

// Assuming the existence of a function "cfftz" similar to the Fortran one.
extern void cfftz(int is, int logd3, int d3, std::complex<double> y1[][fftblockpad], std::complex<double> y2[][fftblockpad]);

void cffts3(int is, int d1, int d2, int d3, std::complex<double> x[][d2][d3], std::complex<double> xout[][d2][d3], std::complex<double> y1[][fftblockpad], std::complex<double> y2[][fftblockpad]) {
    int logd3 = static_cast<int>(std::log2(static_cast<double>(d3)));

    if (timers_enabled) timer_start(T_fftz);

    for (int j = 0; j < d2; ++j) {
        for (int in = 0; in < d1 / fftblock; ++in) {
            int ii = in * fftblock;
            for (int k = 0; k < d3; ++k) {
                for (int i = 0; i < fftblock; ++i) {
                    y1[i][k] = x[i + ii][j][k];
                }
            }

            cfftz(is, logd3, d3, y1, y2);

            for (int k = 0; k < d3; ++k) {
                for (int i = 0; i < fftblock; ++i) {
                    xout[i + ii][j][k] = y1[i][k];
                }
            }
        }
    }

    if (timers_enabled) timer_stop(T_fftz);
}
