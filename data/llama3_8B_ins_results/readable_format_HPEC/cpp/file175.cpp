#include <iostream>
#include <vector>
#include <random>

using namespace std;

void compute_initial_conditions(vector<complex<double>> u0, int d1, int d2, int d3) {
  int k, j;
  double x0, start, an, dummy;
  vector<double> starts(d3);

  start = 1234567890.0; // seed value
  an = 1.0;
  dummy = randlc(start, an);
  an = pow(2.0, 2 * d1 * d2);
  dummy = randlc(start, an);

  starts[0] = start;
  for (k = 1; k < d3; k++) {
    dummy = randlc(start, an);
    starts[k] = start;
  }

  for (k = 0; k < d3; k++) {
    x0 = starts[k];
    for (j = 0; j < d2; j++) {
      vranlc(2 * d1, x0, a, u0(0, j, k));
    }
  }
}

int main() {
  int d1 = 10, d2 = 20, d3 = 30;
  vector<complex<double>> u0(d1 + 1, d2, d3);
  compute_initial_conditions(u0, d1, d2, d3);
  return 0;
}
