#include <iostream>
#include <cmath>

using namespace std;

// assuming these variables are defined elsewhere
double c2, dxi, deta, dzeta;
int ii1, ii2, ji1, ji2;
int ibeg, ifin, ifin1, jbeg, jfin, jfin1;
double u[5][ifin][jfin][ki2]; // assuming ki2 is the size of the k dimension
double phi1[ifin][jfin], phi2[ifin][jfin];

void pintgr() {
  ibeg = ii1;
  ifin = ii2;
  jbeg = ji1;
  jfin = ji2;
  ifin1 = ifin - 1;
  jfin1 = jfin - 1;

  for (int j = jbeg; j <= jfin; j++) {
    for (int i = ibeg; i <= ifin; i++) {
      double k = ki1;
      phi1(i, j) = c2 * (u[5][i][j][k] -
                         0.5 * (u[2][i][j][k] * u[2][i][j][k] +
                                u[3][i][j][k] * u[3][i][j][k] +
                                u[4][i][j][k] * u[4][i][j][k]) /
                         u[1][i][j][k]);
      k = ki2;
      phi2(i, j) = c2 * (u[5][i][j][k] -
                         0.5 * (u[2][i][j][k] * u[2][i][j][k] +
                                u[3][i][j][k] * u[3][i][j][k] +
                                u[4][i][j][k] * u[4][i][j][k]) /
                         u[1][i][j][k]);
    }
  }

  double frc1 = 0.0;
  for (int j = jbeg; j <= jfin1; j++) {
    for (int i = ibeg; i <= ifin1; i++) {
      frc1 += phi1(i, j) + phi1(i + 1, j) + phi1(i, j + 1) + phi1(i + 1, j + 1) +
              phi2(i, j) + phi2(i + 1, j) + phi2(i, j + 1) + phi2(i + 1, j + 1);
    }
  }
  frc1 *= dxi * deta;

  for (int k = ki1; k <= ki2; k++) {
    for (int i = ibeg; i <= ifin; i++) {
      phi1(i, k) = c2 * (u[5][i][jbeg][k] -
                         0.5 * (u[2][i][jbeg][k] * u[2][i][jbeg][k] +
                                u[3][i][jbeg][k] * u[3][i][jbeg][k] +
                                u[4][i][jbeg][k] * u[4][i][jbeg][k]) /
                         u[1][i][jbeg][k]);
    }
  }
  for (int k = ki1; k <= ki2; k++) {
    for (int i = ibeg; i <= ifin; i++) {
      phi2(i, k) = c2 * (u[5][i][jfin][k] -
                         0.5 * (u[2][i][jfin][k] * u[2][i][jfin][k] +
                                u[3][i][jfin][k] * u[3][i][jfin][k] +
                                u[4][i][jfin][k] * u[4][i][jfin][k]) /
                         u[1][i][jfin][k]);
    }
  }

  double frc2 = 0.0;
  for (int k = ki1; k <= ki2 - 1; k++) {
    for (int i = ibeg; i <= ifin1; i++) {
      frc2 += phi1(i, k) + phi1(i + 1, k) + phi1(i, k + 1) + phi1(i + 1, k + 1) +
              phi2(i, k) + phi2(i + 1, k) + phi2(i, k + 1) + phi2(i + 1, k + 1);
    }
  }
  frc2 *= dxi * dzeta;

  for (int k = ki1; k <= ki2; k++) {
    for (int j = jbeg; j <= jfin; j++) {
      phi1(j, k) = c2 * (u[5][ibeg][j][k] -
                         0.5 * (u[2][ibeg][j][k] * u[2][ibeg][j][k] +
                                u[3][ibeg][j][k] * u[3][ibeg][j][k] +
                                u[4][ibeg][j][k] * u[4][ibeg][j][k]) /
                         u[1][ibeg][j][k]);
    }
  }
  for (int k = ki1; k <= ki2; k++) {
    for (int j = jbeg; j <= jfin; j++) {
      phi2(j, k) = c2 * (u[5][ifin][j][k] -
                         0.5 * (u[2][ifin][j][k] * u[2][ifin][j][k] +
                                u[3][ifin][j][k] * u[3][ifin][j][k] +
                                u[4][ifin][j][k] * u[4][ifin][j][k]) /
                         u[1][ifin][j][k]);
    }
  }

  double frc3 = 0.0;
  for (int k = ki1; k <= ki2 - 1; k++) {
    for (int j = jbeg; j <= jfin1; j++) {
      frc3 += phi1(j, k) + phi1(j + 1, k) + phi1(j, k + 1) + phi1(j + 1, k + 1) +
              phi2(j, k) + phi2(j + 1, k) + phi2(j, k + 1) + phi2(j + 1, k + 1);
    }
  }
  frc3 *= deta * dzeta;

  double frc = 0.25 * (frc1 + frc2 + frc3);
}
