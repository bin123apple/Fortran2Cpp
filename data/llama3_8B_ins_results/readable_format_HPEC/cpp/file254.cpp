#include <iostream>
#include <vector>

using namespace std;

void kernel_ludcmp(int n, vector<vector<double>>& a, vector<double>& b, vector<double>& x, vector<double>& y) {
  double w;
  int i, j, k;

  // Initialize b(1) to 1.0
  b[0] = 1.0;

  // Loop through rows
  for (i = 0; i < n; i++) {
    // Loop through columns
    for (j = i + 1; j <= n; j++) {
      w = a[i][j];
      // Loop through previous rows
      for (k = 0; k < i; k++) {
        w -= a[k][j] * a[i][k];
      }
      a[i][j] = w / a[i][i];
    }
  }

  // Loop through rows
  for (i = 0; i < n; i++) {
    // Loop through columns
    for (j = i + 1; j <= n; j++) {
      w = a[j][i + 1];
      // Loop through previous rows
      for (k = 0; k < i; k++) {
        w -= a[k][i + 1] * a[j][k];
      }
      a[j][i + 1] = w;
    }
  }

  // Initialize y(1) to b(1)
  y[0] = b[0];

  // Loop through rows
  for (i = 1; i <= n; i++) {
    w = b[i];
    // Loop through previous rows
    for (j = 0; j < i; j++) {
      w -= a[j][i] * y[j];
    }
    y[i] = w;
  }

  // Initialize x(n + 1) to y(n + 1) / a(n + 1, n + 1)
  x[n] = y[n] / a[n][n];

  // Loop through rows
  for (i = 1; i <= n; i++) {
    w = y[n - i];
    // Loop through columns
    for (j = n + 1 - i; j <= n; j++) {
      w -= a[j][n - i] * x[j];
    }
    x[n - i] = w / a[n - i][n - i];
  }
}
