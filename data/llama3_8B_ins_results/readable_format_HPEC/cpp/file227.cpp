#include <iostream>
#include <vector>

using namespace std;

void kernel_gemm(int ni, int nj, int nk, double alpha, double beta, vector<vector<double>>& c, const vector<vector<double>>& a, const vector<vector<double>>& b) {
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nj; j++) {
      c[j][i] *= beta;
    }
  }
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nj; j++) {
      for (int k = 0; k < nk; k++) {
        c[j][i] += alpha * a[k][i] * b[j][k];
      }
    }
  }
}
