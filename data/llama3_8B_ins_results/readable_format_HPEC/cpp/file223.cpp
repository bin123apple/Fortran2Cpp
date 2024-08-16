#include <iostream>
#include <vector>

using namespace std;

void kernel_gemver(int n, double alpha, double beta, vector<vector<double>>& a,
                   vector<double>& u1, vector<double>& u2, vector<double>& v1,
                   vector<double>& v2, vector<double>& w, vector<double>& x,
                   vector<double>& y, vector<double>& z) {
  // Initialize variables
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[j][i] = a[j][i] + (u1[i] * v1[j]) + (u2[i] * v2[j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      x[i] = x[i] + (beta * a[i][j] * y[j]);
    }
  }

  for (int i = 0; i < n; i++) {
    x[i] = x[i] + z[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      w[i] = w[i] + (alpha * a[j][i] * x[j]);
    }
  }
}

int main() {
  int n = 10; // Replace with the actual value of _PB_N
  double alpha = 1.0;
  double beta = 2.0;

  vector<vector<double>> a(n, vector<double>(n));
  vector<double> u1(n);
  vector<double> u2(n);
  vector<double> v1(n);
  vector<double> v2(n);
  vector<double> w(n);
  vector<double> x(n);
  vector<double> y(n);
  vector<double> z(n);

  // Initialize variables
  //...

  kernel_gemver(n, alpha, beta, a, u1, u2, v1, v2, w, x, y, z);

  return 0;
}
