#include <iostream>
#include <cmath>

using namespace std;

void setcoeff(double& dxi, double& deta, double& dzeta, double& tx1, double& tx2, double& tx3,
              double& ty1, double& ty2, double& ty3, double& tz1, double& tz2, double& tz3,
              double& dx1, double& dx2, double& dx3, double& dx4, double& dx5,
              double& dy1, double& dy2, double& dy3, double& dy4, double& dy5,
              double& dz1, double& dz2, double& dz3, double& dz4, double& dz5,
              double& dssp, double ce[13][13]) {
  dxi = 1.0 / (nx0 - 1);
  deta = 1.0 / (ny0 - 1);
  dzeta = 1.0 / (nz0 - 1);

  tx1 = 1.0 / (dxi * dxi);
  tx2 = 1.0 / (2.0 * dxi);
  tx3 = 1.0 / dxi;

  ty1 = 1.0 / (deta * deta);
  ty2 = 1.0 / (2.0 * deta);
  ty3 = 1.0 / deta;

  tz1 = 1.0 / (dzeta * dzeta);
  tz2 = 1.0 / (2.0 * dzeta);
  tz3 = 1.0 / dzeta;

  dx1 = 0.75;
  dx2 = dx1;
  dx3 = dx1;
  dx4 = dx1;
  dx5 = dx1;

  dy1 = 0.75;
  dy2 = dy1;
  dy3 = dy1;
  dy4 = dy1;
  dy5 = dy1;

  dz1 = 1.0;
  dz2 = dz1;
  dz3 = dz1;
  dz4 = dz1;
  dz5 = dz1;

  dssp = max(dx1, max(dy1, dz1)) / 4.0;

  ce[1][1] = 2.0;
  ce[1][2] = 0.0;
  ce[1][3] = 0.0;
  ce[1][4] = 4.0;
  ce[1][5] = 5.0;
  ce[1][6] = 3.0;
  ce[1][7] = 0.5;
  ce[1][8] = 0.02;
  ce[1][9] = 0.01;
  ce[1][10] = 0.03;
  ce[1][11] = 0.5;
  ce[1][12] = 0.4;
  ce[1][13] = 0.3;

  ce[2][1] = 1.0;
  ce[2][2] = 0.0;
  ce[2][3] = 0.0;
  ce[2][4] = 0.0;
  ce[2][5] = 1.0;
  ce[2][6] = 2.0;
  ce[2][7] = 3.0;
  ce[2][8] = 0.01;
  ce[2][9] = 0.03;
  ce[2][10] = 0.02;
  ce[2][11] = 0.4;
  ce[2][12] = 0.3;
  ce[2][13] = 0.5;

  ce[3][1] = 2.0;
  ce[3][2] = 2.0;
  ce[3][3] = 0.0;
  ce[3][4] = 0.0;
  ce[3][5] = 0.0;
  ce[3][6] = 2.0;
  ce[3][7] = 3.0;
  ce[3][8] = 0.04;
  ce[3][9] = 0.03;
  ce[3][10] = 0.05;
  ce[3][11] = 0.3;
  ce[3][12] = 0.5;
  ce[3][13] = 0.4;

  ce[4][1] = 2.0;
  ce[4][2] = 2.0;
  ce[4][3] = 0.0;
  ce[4][4] = 0.0;
  ce[4][5] = 0.0;
  ce[4][6] = 2.0;
  ce[4][7] = 3.0;
  ce[4][8] = 0.03;
  ce[4][9] = 0.05;
  ce[4][10] = 0.04;
  ce[4][11] = 0.2;
  ce[4][12] = 0.1;
  ce[4][13] = 0.3;

  ce[5][1] = 5.0;
  ce[5][2] = 4.0;
  ce[5][3] = 3.0;
  ce[5][4] = 2.0;
  ce[5][5] = 0.01;
  ce[5][6] = 0.4;
  ce[5][7] = 0.3;
  ce[5][8] = 0.05;
  ce[5][9] = 0.04;
  ce[5][10] = 0.03;
  ce[5][11] = 0.01;
  ce[5][12] = 0.3;
  ce[5][13] = 0.2;
}
