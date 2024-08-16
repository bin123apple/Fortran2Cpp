#include <iostream>
#include <vector>

using namespace std;

void init_array(int ni, int nj, double alpha, double beta, vector<vector<double>>& c, vector<vector<double>>& a, vector<vector<double>>& b) {
  vector<vector<double>> a(nj, vector<double>(ni));
  vector<vector<double>> b(nj, vector<double>(ni));
  vector<vector<double>> c(ni, vector<double>(ni));

  alpha = 32412.0;
  beta = 2123.0;

  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nj; j++) {
      a[j][i] = (double(i - 1) * double(j - 1)) / ni;
      b[j][i] = (double(i - 1) * double(j - 1)) / ni;
    }
  }

  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < ni; j++) {
      c[j][i] = (double(i - 1) * double(j - 1)) / ni;
    }
  }
}
