#include <iostream>
#include <vector>

using namespace std;

void init_array(double& cz, double& cxm, double& cym, double& mui, double& ch, 
                 vector<vector<vector<double>>>& ex, vector<vector<vector<double>>>& ey, 
                 vector<vector<double>>& hz, vector<vector<double>>& ry, vector<double>& ax, 
                 vector<double>& cymh, vector<double>& cyph, vector<double>& cxmh, vector<double>& cxph, 
                 vector<double>& czm, vector<double>& czp) {
  mui = 2341.0;
  ch = 42.0;

  for (int i = 0; i <= int(cz); i++) {
    czm[i] = (double(i - 1) + 1.0) / cxm;
    czp[i] = (double(i - 1) + 2.0) / cxm;
  }

  for (int i = 0; i <= int(cxm); i++) {
    cxmh[i] = (double(i - 1) + 3.0) / cxm;
    cxph[i] = (double(i - 1) + 4.0) / cxm;
  }

  for (int i = 0; i <= int(cym); i++) {
    cymh[i] = (double(i - 1) + 5.0) / cxm;
    cyph[i] = (double(i - 1) + 6.0) / cxm;
  }

  for (int i = 0; i <= int(cz); i++) {
    for (int j = 0; j <= int(cym); j++) {
      ry[j][i] = ((double(i - 1) * double(j)) + 10.0) / cym;
      ax[j][i] = ((double(i - 1) * double(j + 1)) + 11.0) / cym;
    }
  }

  for (int i = 0; i <= int(cz); i++) {
    for (int j = 0; j <= int(cym); j++) {
      for (int k = 0; k <= int(cxm); k++) {
        ex[k][j][i] = ((double(i - 1) * double(j + 2)) + double(k - 1) + 1.0) / cxm;
        ey[k][j][i] = ((double(i - 1) * double(j + 3)) + double(k - 1) + 2.0) / cym;
        hz[k][j][i] = ((double(i - 1) * double(j + 4)) + double(k - 1) + 3.0) / cz;
      }
    }
  }
}
