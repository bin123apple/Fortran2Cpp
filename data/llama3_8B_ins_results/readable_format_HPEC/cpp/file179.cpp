#include <complex>
#include <iostream>

void cffts2(int is, int d1, int d2, int d3, std::complex<double> x[d1+1][d2][d3], std::complex<double> xout[d1+1][d2][d3], std::complex<double> y1[fftblockpad][d2], std::complex<double> y2[fftblockpad][d2]) {
  int logd2 = std::log2(d2);
  int fftblock = 256; // assume fftblock is a constant

  if (timers_enabled) {
    timer_start(T_ffty);
  }

  for (int k = 0; k < d3; k++) {
    for (int in = 0; in < d1/fftblock; in++) {
      int ii = in * fftblock;
      for (int j = 0; j < d2; j++) {
        for (int i = 0; i < fftblock; i++) {
          y1[i][j] = x[i+ii][j][k];
        }
      }
    }
  }

  cfftz(is, logd2, d2, y1, y2);

  for (int j = 0; j < d2; j++) {
    for (int i = 0; i < fftblock; i++) {
      xout[i+ii][j][k] = y1[i][j];
    }
  }

  if (timers_enabled) {
    timer_stop(T_ffty);
  }
}
