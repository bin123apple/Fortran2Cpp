#include <complex>
#include <vector>
#include <cmath>

// Assuming ft_data is a header file that defines some constants or types used in the original Fortran code.
// #include "ft_data.h"

// Assuming fftblockpad and T_fftx are defined somewhere in the C++ codebase.
const int fftblockpad = /* appropriate value */;

// Forward declaration of cfftz, assuming it's implemented elsewhere.
void cfftz(int is, int logd1, int d1, std::complex<double>** y1, std::complex<double>** y2);

// Assuming timer_start, timer_stop are part of a timer utility.
// void timer_start(int timer);
// void timer_stop(int timer);

void cffts1(int is, int d1, int d2, int d3, std::complex<double>*** x, std::complex<double>*** xout, std::complex<double>** y1, std::complex<double>** y2) {
    int logd1 = static_cast<int>(std::log2(d1));

    if (timers_enabled) timer_start(T_fftx);

    for (int k = 0; k < d3; ++k) {
        for (int jn = 0; jn < d2 / fftblock - 1; ++jn) {
            int jj = jn * fftblock;
            for (int j = 0; j < fftblock; ++j) {
                for (int i = 0; i < d1; ++i) {
                    y1[j][i] = x[i][j + jj][k];
                }
            }
        }
    }

    cfftz(is, logd1, d1, y1, y2);

    for (int k = 0; k < d3; ++k) {
        for (int jn = 0; jn < d2 / fftblock - 1; ++jn) {
            int jj = jn * fftblock;
            for (int j = 0; j < fftblock; ++j) {
                for (int i = 0; i < d1; ++i) {
                    xout[i][j + jj][k] = y1[j][i];
                }
            }
        }
    }

    if (timers_enabled) timer_stop(T_fftx);
}
