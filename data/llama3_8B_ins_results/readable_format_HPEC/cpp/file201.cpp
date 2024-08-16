#include <iostream>
#include <vector>

using namespace std;

// Define the data type
typedef double DATA_TYPE;

// Define the function
void kernel_fdtd_apml(DATA_TYPE cz, DATA_TYPE cxm, DATA_TYPE cym, DATA_TYPE mui, DATA_TYPE ch,
                        vector<vector<vector<DATA_TYPE>>> ex, vector<vector<vector<DATA_TYPE>>> ey,
                        vector<vector<vector<DATA_TYPE>>> hz, vector<vector<DATA_TYPE>> clf, vector<DATA_TYPE> ry,
                        vector<vector<DATA_TYPE>> ax, vector<DATA_TYPE> cymh, vector<DATA_TYPE> cyph,
                        vector<DATA_TYPE> cxmh, vector<DATA_TYPE> cxph, vector<DATA_TYPE> czm, vector<DATA_TYPE> czp,
                        vector<vector<DATA_TYPE>> tmp, vector<vector<DATA_TYPE>> bza) {
  int _PB_CZ = cz + 1;
  int _PB_CYM = cym + 1;
  int _PB_CXM = cxm + 1;

  for (int iz = 1; iz < _PB_CZ; iz++) {
    for (int iy = 1; iy < _PB_CYM; iy++) {
      for (int ix = 1; ix < _PB_CXM; ix++) {
        clf[iy][iz] = ex[ix][iy][iz] - ex[ix][iy + 1][iz] + ey[ix + 1][iy][iz] - ey[ix][iy][iz];
        tmp[iy][iz] = ((cymh[iy] / cyph[iy]) * bza[ix][iy][iz]) - ((ch / cyph[iy]) * clf[iy][iz]);
        hz[ix][iy][iz] = ((cxmh[ix] / cxph[ix]) * hz[ix][iy][iz]) +
                         ((mui * czp[iz] / cxph[ix]) * tmp[iy][iz]) -
                         ((mui * czm[iz] / cxph[ix]) * bza[ix][iy][iz]);
        bza[ix][iy][iz] = tmp[iy][iz];
      }
    }
  }

  for (int iz = 1; iz < _PB_CZ; iz++) {
    for (int iy = 1; iy < _PB_CYM; iy++) {
      clf[iy][iz] = ex[_PB_CXM + 1][iy][iz] - ex[_PB_CXM + 1][iy + 1][iz] + ry[iy][iz] - ey[_PB_CXM + 1][iy][iz];
      tmp[iy][iz] = ((cymh[iy] / cyph[iy]) * bza[_PB_CXM + 1][iy][iz]) - ((ch / cyph[iy]) * clf[iy][iz]);
      hz[_PB_CXM + 1][iy][iz] = ((cxmh[_PB_CXM + 1] / cxph[_PB_CXM + 1]) * hz[_PB_CXM + 1][iy][iz]) +
                               ((mui * czp[iz] / cxph[_PB_CXM + 1]) * tmp[iy][iz]) -
                               ((mui * czm[iz] / cxph[_PB_CXM + 1]) * bza[_PB_CXM + 1][iy][iz]);
      bza[_PB_CXM + 1][iy][iz] = tmp[iy][iz];
    }
  }

  for (int iz = 1; iz < _PB_CZ; iz++) {
    clf[iy][iz] = ex[ix][_PB_CYM + 1][iz] - ax[ix][iz] + ey[ix + 1][_PB_CYM + 1][iz] - ey[ix][_PB_CYM + 1][iz];
    tmp[iy][iz] = ((cymh[_PB_CYM + 1] / cyph[iy]) * bza[ix][iy][iz]) - ((ch / cyph[iy]) * clf[iy][iz]);
    hz[ix][_PB_CYM + 1][iz] = ((cxmh[ix] / cxph[ix]) * hz[ix][_PB_CYM + 1][iz]) +
                             ((mui * czp[iz] / cxph[ix]) * tmp[iy][iz]) -
                             ((mui * czm[iz] / cxph[ix]) * bza[ix][_PB_CYM + 1][iz]);
    bza[ix][_PB_CYM + 1][iz] = tmp[iy][iz];
  }

  clf[iy][iz] = ex[_PB_CXM + 1][_PB_CYM + 1][iz] - ax[_PB_CXM + 1][iz] + ry[_PB_CYM + 1][iz] - ey[_PB_CXM + 1][_PB_CYM + 1][iz];
  tmp[iy][iz] = ((cymh[_PB_CYM + 1] / cyph[_PB_CYM + 1]) * bza[_PB_CXM + 1][_PB_CYM + 1][iz]) -
                ((ch / cyph[_PB_CYM + 1]) * clf[iy][iz]);
  hz[_PB_CXM + 1][_PB_CYM + 1][iz] = ((cxmh[_PB_CXM + 1] / cxph[_PB_CXM + 1]) * hz[_PB_CXM + 1][_PB_CYM + 1][iz]) +
                                       ((mui * czp[iz] / cxph[_PB_CXM + 1]) * tmp[iy][iz]) -
                                       ((mui * czm[iz] / cxph[_PB_CXM + 1]) * bza[_PB_CXM + 1][_PB_CYM + 1][iz]);
  bza[_PB_CXM + 1][_PB_CYM + 1][iz] = tmp[iy][iz];
}

int main() {
  // Initialize the arrays
  int cz = 10;
  int cxm = 10;
  int cym = 10;
  double mui = 1.0;
  double ch = 1.0;

  vector<vector<vector<double>>> ex(cxm + 1, vector<vector<double>>(cym + 1, vector<double>(cz + 1)));
  vector<vector<vector<double>>> ey(cxm + 1, vector<vector<double>>(cym + 1, vector<double>(cz + 1)));
  vector<vector<vector<double>>> hz(cxm + 1, vector<vector<double>>(cym + 1, vector<double>(cz + 1)));
  vector<vector<double>> clf(cym + 1, vector<double>(cz + 1));
  vector<double> ry(cym + 1, vector<double>(cz + 1));
  vector<double> ax(cxm + 1, vector<double>(cz + 1));
  vector<double> cymh(cym + 1);
  vector<double> cyph(cym + 1);
  vector<double> cxmh(cxm + 1);
  vector<double> cxph(cxm + 1);
  vector<double> czm(cz + 1);
  vector<double> czp(cz + 1);
  vector<vector<double>> tmp(cxm + 1, vector<vector<double>>(cym + 1, vector<double>(cz + 1)));
  vector<vector<double>> bza(cxm + 1, vector<vector<double>>(cym + 1, vector<double>(cz + 1)));

  // Call the kernel function
  kernel_fdtd_apml(cz, cxm, cym, mui, ch, ex, ey, hz, clf, ry, ax, cymh, cyph, cxmh, cxph, czm, czp, tmp, bza);

  return 0;
}
