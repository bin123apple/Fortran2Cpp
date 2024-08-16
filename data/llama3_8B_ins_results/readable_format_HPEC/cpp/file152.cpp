#include <iostream>
#include <cmath>

using namespace std;

void ninvr(double ***rhs, double bt, int nx2, int ny2, int nz2) {
  if (timeron) {
    timer_start(t_ninvr);
  }

  for (int k = 1; k <= nz2; k++) {
    for (int j = 1; j <= ny2; j++) {
      for (int i = 1; i <= nx2; i++) {
        double r1 = rhs[0][i][j][k];
        double r2 = rhs[1][i][j][k];
        double r3 = rhs[2][i][j][k];
        double r4 = rhs[3][i][j][k];
        double r5 = rhs[4][i][j][k];

        double t1 = bt * r3;
        double t2 = 0.5 * (r4 + r5);

        rhs[0][i][j][k] = -r2;
        rhs[1][i][j][k] = r1;
        rhs[2][i][j][k] = bt * (r4 - r5);
        rhs[3][i][j][k] = -t1 + t2;
        rhs[4][i][j][k] = t1 + t2;
      }
    }
  }

  if (timeron) {
    timer_stop(t_ninvr);
  }
}
