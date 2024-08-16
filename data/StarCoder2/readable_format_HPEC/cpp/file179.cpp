#include "ft_data.h"
#include <complex>
#include <cmath>

void cffts2(int is, int d1, int d2, int d3, std::complex<double> x[][MAX_D2][MAX_D3], 
            std::complex<double> xout[][MAX_D2][MAX_D3], 
            std::complex<double> y1[FFTBLOCKPAD][MAX_D2], 
            std::complex<double> y2[FFTBLOCKPAD][MAX_D2]) {
    
    int logd2 = static_cast<int>(std::log2(static_cast<double>(d2)));
    int ii, in;

    if (timers_enabled) timer_start(T_ffty);

    for (int k = 0; k < d3; ++k) {
        for (in = 0; in < d1 / fftblock; ++in) {
            ii = in * fftblock;
            for (int j = 0; j < d2; ++j) {
                for (int i = 0; i < fftblock; ++i) {
                    y1[i][j] = x[i + ii][j][k];
                }
            }

            cfftz(is, logd2, d2, y1, y2);

            for (int j = 0; j < d2; ++j) {
                for (int i = 0; i < fftblock; ++i) {
                    xout[i + ii][j][k] = y1[i][j];
                }
            }
        }
    }

    if (timers_enabled) timer_stop(T_ffty);
}
