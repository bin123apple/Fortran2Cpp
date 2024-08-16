#include <iostream>
#include <vector>

using namespace std;

void exact_solution(double xi, double eta, double zeta, vector<double>& dtemp) {
  const int m_max = 5;
  const vector<vector<double>> ce = {{1, 2, 4, 7, 11}, {3, 6, 9, 12}, {4, 7, 10, 13}, {5, 8, 11, 13}, {8, 11, 13, 13}}; // assuming this is the ce array

  for (int m = 1; m <= m_max; ++m) {
    dtemp[m - 1] = ce[m - 1][0] + 
      xi * (ce[m - 1][1] + xi * (ce[m - 1][4] + xi * (ce[m - 1][7] + xi * ce[m - 1][10]))) + 
      eta * (ce[m - 1][2] + eta * (ce[m - 1][5] + eta * (ce[m - 1][8] + eta * ce[m - 1][11]))) + 
      zeta * (ce[m - 1][3] + zeta * (ce[m - 1][6] + zeta * (ce[m - 1][9] + zeta * ce[m - 1][12])));
  }
}

int main() {
  double xi = 0.5; // example values
  double eta = 0.3;
  double zeta = 0.2;
  vector<double> dtemp(5);

  exact_solution(xi, eta, zeta, dtemp);

  // print the result
  for (int m = 1; m <= 5; ++m) {
    cout << "dtemp[" << m << "] = " << dtemp[m - 1] << endl;
  }

  return 0;
}
