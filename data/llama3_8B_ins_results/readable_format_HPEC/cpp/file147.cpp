#include <iostream>
#include <cmath>

using namespace std;

const double c1 = 1.4;
const double c2 = 0.4;
const double c3 = 0.1;
const double c4 = 1.0;
const double c5 = 1.4;

const double bt = sqrt(0.5);

int grid_points[3]; // assuming this is an array of 3 integers

double dnxm1, dnym1, dnzm1; // assuming these are double variables

double ce[4][13]; // assuming this is a 4x13 array of doubles

int main() {
  // initialize ce array
  ce[0][1] = 2.0;
  ce[0][2] = 0.0;
  ce[0][3] = 0.0;
  ce[0][4] = 4.0;
  ce[0][5] = 5.0;
  ce[0][6] = 3.0;
  ce[0][7] = 0.5;
  ce[0][8] = 0.02;
  ce[0][9] = 0.01;
  ce[0][10] = 0.03;
  ce[0][11] = 0.5;
  ce[0][12] = 0.4;
  ce[0][13] = 0.3;

  ce[1][1] = 1.0;
  ce[1][2] = 0.0;
  ce[1][3] = 0.0;
  ce[1][4] = 0.0;
  ce[1][5] = 1.0;
  ce[1][6] = 2.0;
  ce[1][7] = 3.0;
  ce[1][8] = 0.01;
  ce[1][9] = 0.03;
  ce[1][10] = 0.02;
  ce[1][11] = 0.4;
  ce[1][12] = 0.3;
  ce[1][13] = 0.5;

  //...

  // calculate various constants
  double c1c2 = c1 * c2;
  double c1c5 = c1 * c5;
  double c3c4 = c3 * c4;
  double c1345 = c1c5 * c3c4;

  double conz1 = 1.0 - c1c5;

  double tx1 = 1.0 / (dnxm1 * dnxm1);
  double tx2 = 1.0 / (2.0 * dnxm1);
  double tx3 = 1.0 / dnxm1;

  double ty1 = 1.0 / (dnym1 * dnym1);
  double ty2 = 1.0 / (2.0 * dnym1);
  double ty3 = 1.0 / dnym1;

  double tz1 = 1.0 / (dnzm1 * dnzm1);
  double tz2 = 1.0 / (2.0 * dnzm1);
  double tz3 = 1.0 / dnzm1;

  double dx1 = 0.75;
  double dx2 = 0.75;
  double dx3 = 0.75;
  double dx4 = 0.75;
  double dx5 = 0.75;

  double dy1 = 0.75;
  double dy2 = 0.75;
  double dy3 = 0.75;
  double dy4 = 0.75;
  double dy5 = 0.75;

  double dz1 = 1.0;
  double dz2 = 1.0;
  double dz3 = 1.0;
  double dz4 = 1.0;
  double dz5 = 1.0;

  double dxmax = max(dx3, dx4);
  double dymax = max(dy2, dy4);
  double dzmax = max(dz2, dz3);

  double dssp = 0.25 * max(dx1, max(dy1, dz1));
  double c4dssp = 4.0 * dssp;
  double c5dssp = 5.0 * dssp;

  double dttx1 = dt * tx1;
  double dttx2 = dt * tx2;
  double dtty1 = dt * ty1;
  double dtty2 = dt * ty2;
  double dttz1 = dt * tz1;
  double dttz2 = dt * tz2;

  double c2dttx1 = 2.0 * dttx1;
  double c2dtty1 = 2.0 * dtty1;
  double c2dttz1 = 2.0 * dttz1;

  double dtdssp = dt * dssp;

  double comz1 = dtdssp;
  double comz4 = 4.0 * dtdssp;
  double comz5 = 5.0 * dtdssp;
  double comz6 = 6.0 * dtdssp;

  double c3c4tx3 = c3c4 * tx3;
  double c3c4ty3 = c3c4 * ty3;
  double c3c4tz3 = c3c4 * tz3;

  double dx1tx1 = dx1 * tx1;
  double dx2tx1 = dx2 * tx1;
  double dx3tx1 = dx3 * tx1;
  double dx4tx1 = dx4 * tx1;
  double dx5tx1 = dx5 * tx1;

  double dy1ty1 = dy1 * ty1;
  double dy2ty1 = dy2 * ty1;
  double dy3ty1 = dy3 * ty1;
  double dy4ty1 = dy4 * ty1;
  double dy5ty1 = dy5 * ty1;

  double dz1tz1 = dz1 * tz1;
  double dz2tz1 = dz2 * tz1;
  double dz3tz1 = dz3 * tz1;
  double dz4tz1 = dz4 * tz1;
  double dz5tz1 = dz5 * tz1;

  double c2iv = 2.5;
  double con43 = 4.0 / 3.0;
  double con16 = 1.0 / 6.0;

  double xxcon1 = c3c4tx3 * con43 * tx3;
  double xxcon2 = c3c4tx3 * tx3;
  double xxcon3 = c3c4tx3 * conz1 * tx3;
  double xxcon4 = c3c4tx3 * con16 * tx3;
  double xxcon5 = c3c4tx3 * c1c5 * tx3;

  double yycon1 = c3c4ty3 * con43 * ty3;
  double yycon2 = c3c4ty3 * ty3;
  double yycon3 = c3c4ty3 * conz1 * ty3;
  double yycon4 = c3c4ty3 * con16 * ty3;
  double yycon5 = c3c4ty3 * c1c5 * ty3;

  double zzcon1 = c3c4tz3 * con43 * tz3;
  double zzcon2 = c3c4tz3 * tz3;
  double zzcon3 = c3c4tz3 * conz1 * tz3;
  double zzcon4 = c3c4tz3 * con16 * tz3;
  double zzcon5 = c3c4tz3 * c1c5 * tz3;

  return 0;
}
