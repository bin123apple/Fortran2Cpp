#include <complex>
#include <cmath>

// Assuming the existence of a function cfftz that performs the actual FFT operation
// and that ft_data.h or similar header file defines necessary constants and types.
#include "ft_data.h"

void cffts1(int is, int d1, int d2, int d3, 
            std::complex<double> x[d1+1][d2][d3], 
            std::complex<double> xout[d1+1][d2][d3], 
            std::complex<double> y1[FFTBLOCKPAD][d1], 
            std::complex<double> y2[FFTBLOCKPAD][d1]) {
    
    int logd1 = static_cast<int>(std::log2(static_cast<double>(d1)));
    int i, j, k, jj, jn;

    if (timers_enabled) timer_start(T_fftx);

    for (k = 0; k < d3; ++k) {
        for (jn = 0; jn < d2 / FFTBLOCK; ++jn) {
            jj = jn * FFTBLOCK;
            for (j = 0; j < FFTBLOCK; ++j) {
                for (i = 0; i < d1; ++i) {
                    y1[j][i] = x[i][j + jj][k];
                }
            }

            cfftz(is, logd1, d1, y1, y2);

            for (j = 0; j < FFTBLOCK; ++j) {
                for (i = 0; i < d1; ++i) {
                    xout[i][j + jj][k] = y1[j][i];
                }
            }
        }
    }

    if (timers_enabled) timer_stop(T_fftx);
}
