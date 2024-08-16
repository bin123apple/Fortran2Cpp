#include <iostream>
#include <vector>

using namespace std;

void kernel_2mm(double alpha, double beta, vector<vector<double>>& tmp, 
                 vector<vector<double>>& a, vector<vector<double>>& b, 
                 vector<vector<double>>& c, vector<vector<double>>& d, 
                 int ni, int nj, int nk, int nl) {
  // Initialize tmp array
  tmp.resize(nj, ni);
  for (int j = 0; j < nj; j++) {
    for (int i = 0; i < ni; i++) {
      tmp[j][i] = 0.0;
    }
  }

  // Compute tmp array
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nj; j++) {
      for (int k = 0; k < nk; k++) {
        tmp[j][i] += alpha * a[k][i] * b[j][k];
      }
    }
  }

  // Compute d array
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nl; j++) {
      d[j][i] = d[j][i] * beta;
      for (int k = 0; k < nj; k++) {
        d[j][i] += tmp[k][i] * c[j][k];
      }
    }
  }
}

int main() {
  // Initialize arrays
  int ni = 10;
  int nj = 20;
  int nk = 30;
  int nl = 40;
  vector<vector<double>> a(nk, vector<double>(ni));
  vector<vector<double>> b(nj, vector<double>(nk));
  vector<vector<double>> c(nl, vector<double>(nj));
  vector<vector<double>> d(nl, vector<double>(ni));
  vector<vector<double>> tmp(nj, vector<double>(ni));

  // Set values for a, b, c, d
  //...

  // Call kernel_2mm
  double alpha = 0.5;
  double beta = 0.3;
  kernel_2mm(alpha, beta, tmp, a, b, c, d, ni, nj, nk, nl);

  // Print results
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nl; j++) {
      cout << d[j][i] << " ";
    }
    cout << endl;
  }

  return 0;
}
