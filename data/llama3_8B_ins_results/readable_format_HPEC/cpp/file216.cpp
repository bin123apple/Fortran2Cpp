#include <iostream>
#include <vector>

using namespace std;

void kernel_jacobi1d(int tsteps, int n, vector<double>& a, vector<double>& b) {
  for (int t = 1; t <= tsteps; t++) {
    for (int i = 2; i < n - 1; i++) {
      b[i] = 0.33333 * (a[i - 1] + a[i] + a[i + 1]);
    }
    for (int j = 2; j < n - 1; j++) {
      a[j] = b[j];
    }
  }
}

int main() {
  int tsteps = 1; // adjust this value as needed
  int n = 100; // adjust this value as needed
  vector<double> a(n);
  vector<double> b(n);

  // initialize a and b arrays (not shown in the Fortran code)

  kernel_jacobi1d(tsteps, n, a, b);

  // print the resulting arrays (not shown in the Fortran code)

  return 0;
}
