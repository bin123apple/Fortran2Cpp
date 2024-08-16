#include <complex>
#include <iostream>

using namespace std;

void cffts3(int is, int d1, int d2, int d3, complex<double> x[d1+1][d2][d3], complex<double> xout[d1+1][d2][d3], complex<double> y1[fftblockpad][d3], complex<double> y2[fftblockpad][d3]) {
    int logd3 = ilog2(d3);
    int fftblock = 256; // assuming fftblock is a constant

    if (timers_enabled) {
        timer_start(T_fftz);
    }

    for (int j = 0; j < d2; j++) {
        for (int in = 0; in < d1/fftblock; in++) {
            int ii = in*fftblock;
            for (int k = 0; k < d3; k++) {
                for (int i = 0; i < fftblock; i++) {
                    y1[i][k] = x[i+ii][j][k];
                }
            }
        }
    }

    cfftz(is, logd3, d3, y1, y2);

    for (int k = 0; k < d3; k++) {
        for (int i = 0; i < fftblock; i++) {
            xout[i+ii][j][k] = y1[i][k];
        }
    }

    if (timers_enabled) {
        timer_stop(T_fftz);
    }
}
