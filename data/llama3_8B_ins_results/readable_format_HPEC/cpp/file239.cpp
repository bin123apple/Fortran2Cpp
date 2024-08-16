#include <iostream>
#include <vector>

using namespace std;

void kernel_3mm(int ni, int nj, int nk, int nl, int nm, vector<vector<double>>& e, vector<vector<double>>& a, vector<vector<double>>& b, vector<vector<double>>& c, vector<vector<double>>& d, vector<vector<double>>& f, vector<vector<double>>& g) {
  // Allocate memory for arrays
  vector<vector<double>> e_array(nj, vector<double>(ni, 0.0));
  vector<vector<double>> f_array(nl, vector<double>(nj, 0.0));
  vector<vector<double>> g_array(nl, vector<double>(ni, 0.0));

  // E := A*B
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nj; j++) {
      e_array[j][i] = 0.0;
    }
  }
  for (int k = 0; k < nk; k++) {
    for (int i = 0; i < ni; i++) {
      for (int j = 0; j < nj; j++) {
        e_array[j][i] += a[k][i] * b[j][k];
      }
    }
  }

  // F := C*D
  for (int i = 0; i < nj; i++) {
    for (int j = 0; j < nl; j++) {
      f_array[j][i] = 0.0;
    }
  }
  for (int k = 0; k < nm; k++) {
    for (int i = 0; i < nj; i++) {
      for (int j = 0; j < nl; j++) {
        f_array[j][i] += c[k][i] * d[j][k];
      }
    }
  }

  // G := E*F
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nl; j++) {
      g_array[j][i] = 0.0;
    }
  }
  for (int k = 0; k < nj; k++) {
    for (int i = 0; i < ni; i++) {
      for (int j = 0; j < nl; j++) {
        g_array[j][i] += e_array[k][i] * f_array[j][k];
      }
    }
  }

  // Copy results back to output arrays
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < nl; j++) {
      g[j][i] = g_array[j][i];
    }
  }
}
