```C++
extern "C" {
void kernel_ludcmp(int n, double** a, double* b, double* x, double* y) {
  double w;
  b[0] = 1.0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      w = a[i][j];
      for (int k = 0; k < i; ++k)
        w = w - (a[k][j] * a[i][k]);
      a[i][j] = w / a[i][i];
    }
    for (int j = i+1; j <= n; ++j) {
      w = a[j][i+1];
      for (int k = 0; k <= i; ++k)
        w = w - (a[k][i+1] * a[j][k]);
      a[j][i+1] = w;
    }
  }
  y[0] = b[0];
  for (int i = 1; i <= n; ++i) {
    w = b[i];
    for (int j = 0; j < i; ++j)
      w = w - (a[j][i] * y[j]);
    y[i] = w;
  }
  x[n] = y[n] / a[n][n];
  for (int i = 0; i < n; ++i) {
    w = y[n-i];
    for (int j = n-i+1; j <= n; ++j)
      w = w - (a[j][n-i] * x[j]);
    x[n-i] = w / a[n-i][n-i];
  }
}
}
```
