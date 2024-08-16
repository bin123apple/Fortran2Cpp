#include <complex>
#include <iostream>

using namespace std;

void cffts1(int is, int d1, int d2, int d3, complex<double> x[d1+1][d2][d3], complex<double> xout[d1+1][d2][d3], complex<double> y1[fftblockpad][d1], complex<double> y2[fftblockpad][d1]) {
  int i, j, k, jj, jn;
  int logd1 = ilog2(d1);

  if (timers_enabled) {
    timer_start(T_fftx);
  }

  for (k = 0; k < d3; k++) {
    for (jn = 0; jn < d2/fftblock; jn++) {
      jj = jn*fftblock;
      for (j = 0; j < fftblock; j++) {
        for (i = 0; i < d1; i++) {
          y1[j][i] = x[i][j+jj][k];
        }
      }
    }
  }

  cfftz(is, logd1, d1, y1, y2);

  for (j = 0; j < fftblock; j++) {
    for (i = 0; i < d1; i++) {
      xout[i][j+jj][k] = y1[j][i];
    }
  }

  if (timers_enabled) {
    timer_stop(T_fftx);
  }
}
