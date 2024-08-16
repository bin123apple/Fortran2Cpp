#include <cmath>
#define DATA_TYPE double
#define _PB_N n

void kernel_cholesky(int n, DATA_TYPE* p, DATA_TYPE** a) {
  DATA_TYPE x;
  for (int i = 0; i < _PB_N; ++i) {
    x = a[i][i];
    for (int j = 0; j < i; ++j) {
      x = x - a[j][i] * a[j][i];
    }
    p[i] = 1.0 / sqrt(x);
    for (int j = i + 1; j < _PB_N; ++j) {
      x = a[j][i];
      for (int k = 0; k < i; ++k) {
        x = x - (a[k][j] * a[k][i]);
      }
      a[i][j] = x * p[i];
    }
  }
}
