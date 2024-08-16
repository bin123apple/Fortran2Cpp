#include <iostream>
#include <vector>

using namespace std;

void kernel_adi(int tsteps, int n, vector<vector<double>>& x, vector<vector<double>>& a, vector<vector<double>>& b) {
  // Initialize variables
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0.0;
      x[i][j] = 0.0;
      b[i][j] = 0.0;
    }
  }

  // Loop over tsteps
  for (int t = 1; t <= tsteps; t++) {
    // Loop over i1
    for (int i1 = 1; i1 < n; i1++) {
      // Loop over i2
      for (int i2 = 2; i2 < n; i2++) {
        x[i2][i1] = x[i2][i1] - (x[i2 - 1][i1] * a[i2][i1]) / b[i2 - 1][i1];
        b[i2][i1] = b[i2][i1] - (a[i2][i1] * a[i2][i1]) / b[i2 - 1][i1];
      }
    }
  }

  // Loop over i1
  for (int i1 = 1; i1 < n; i1++) {
    x[n - 1][i1] = x[n - 1][i1] / b[n - 1][i1];
  }

  // Loop over i1 and i2
  for (int i1 = 1; i1 < n; i1++) {
    for (int i2 = 1; i2 < n - 2; i2++) {
      x[n - i2 - 1][i1] = (x[n - i2 - 1][i1] - (x[n - i2 - 2][i1] * a[n - i2 - 2][i1])) / b[n - i2 - 2][i1];
    }
  }

  // Loop over i1 and i2
  for (int i1 = 2; i1 < n; i1++) {
    for (int i2 = 1; i2 < n; i2++) {
      x[i2][i1] = x[i2][i1] - x[i2][i1 - 1] * a[i2][i1] / b[i2][i1 - 1];
      b[i2][i1] = b[i2][i1] - a[i2][i1] * a[i2][i1] / b[i2][i1 - 1];
    }
  }

  // Loop over i2
  for (int i2 = 1; i2 < n; i2++) {
    x[i2][n - 1] = x[i2][n - 1] / b[i2][n - 1];
  }

  // Loop over i1 and i2
  for (int i1 = 2; i1 < n; i1++) {
    for (int i2 = 1; i2 < n; i2++) {
      x[i2][n - i1] = (x[i2][n - i1] - x[i2][n - i1 - 1] * a[i2][n - i1 - 1]) / b[i2][n - i1];
    }
  }
}

int main() {
  int tsteps = 10;
  int n = 10;
  vector<vector<double>> x(n, vector<double>(n, 0.0));
  vector<vector<double>> a(n, vector<double>(n, 0.0));
  vector<vector<double>> b(n, vector<double>(n, 0.0));

  kernel_adi(tsteps, n, x, a, b);

  // Print the result
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << x[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
