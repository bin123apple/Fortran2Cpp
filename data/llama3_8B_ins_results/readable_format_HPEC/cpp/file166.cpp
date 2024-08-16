#include <vector>
#include <cmath>

void exact_solution(double xi, double eta, double zeta, std::vector<double>& dtemp) {
  const int M = 5;
  const std::vector<std::vector<double>> ce = {{/* initialize ce values */}};

  for (int m = 1; m <= M; ++m) {
    dtemp[m - 1] = ce[m - 1][0] +
                   xi * (ce[m - 1][1] + xi * (ce[m - 1][4] + xi * (ce[m - 1][7] + xi * ce[m - 1][10]))) +
                   eta * (ce[m - 1][2] + eta * (ce[m - 1][5] + eta * (ce[m - 1][8] + eta * ce[m - 1][11]))) +
                   zeta * (ce[m - 1][3] + zeta * (ce[m - 1][6] + zeta * (ce[m - 1][9] + zeta * ce[m - 1][12])));
  }
}
