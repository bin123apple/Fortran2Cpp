#include <iostream>
#include <cmath>

void init_array(int n, double* x1, double* x2, double* y1, double* y2, double** a) {
  for (int i = 0; i < n; i++) {
    x1[i] = (i - 1) / static_cast<double>(n);
    x2[i] = (i - 1 + 1.0) / static_cast<double>(n);
    y1[i] = (i - 1 + 3.0) / static_cast<double>(n);
    y2[i] = (i - 1 + 4.0) / static_cast<double>(n);
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      a[j][i] = ((i - 1) * (j - 1)) / static_cast<double>(n);
    }
  }
}
