#include <iostream>
#include <vector>

using namespace std;

void kernel_doitgen(int nr, int nq, int np, vector<vector<vector<double>>> &a, vector<vector<double>> &cFour, vector<vector<vector<double>>> &sumA) {
  for (int r = 1; r <= nr; ++r) {
    for (int q = 1; q <= nq; ++q) {
      for (int p = 1; p <= np; ++p) {
        sumA[p-1][q-1][r-1] = 0.0;
      }
      for (int s = 1; s <= np; ++s) {
        sumA[p-1][q-1][r-1] += a[s-1][q-1][r-1] * cFour[p-1][s-1];
      }
      for (int p = 1; p <= np; ++p) {
        a[p-1][q-1][r-1] = sumA[p-1][q-1][r-1];
      }
    }
  }
}
