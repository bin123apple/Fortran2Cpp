#include <iostream>
#include <cmath>

using namespace std;

void pinvr() {
  // Assume these variables are defined elsewhere
  int i, j, k;
  double r1, r2, r3, r4, r5, t1, t2;
  double bt; // assume bt is defined elsewhere
  double* rhs; // assume rhs is a 5D array

  if (timeron) {
    timer_start(t_pinvr);
  }

  for (k = 1; k <= nz2; k++) {
    for (j = 1; j <= ny2; j++) {
      for (i = 1; i <= nx2; i++) {
        r1 = rhs[5 * (i - 1) + 0, i, j, k];
        r2 = rhs[5 * (i - 1) + 1, i, j, k];
        r3 = rhs[5 * (i - 1) + 2, i, j, k];
        r4 = rhs[5 * (i - 1) + 3, i, j, k];
        r5 = rhs[5 * (i - 1) + 4, i, j, k];

        t1 = bt * r1;
        t2 = 0.5 * (r4 + r5);

        rhs[5 * (i - 1) + 0, i, j, k] = bt * (r4 - r5);
        rhs[5 * (i - 1) + 1, i, j, k] = -r3;
        rhs[5 * (i - 1) + 2, i, j, k] = r2;
        rhs[5 * (i - 1) + 3, i, j, k] = -t1 + t2;
        rhs[5 * (i - 1) + 4, i, j, k] = t1 + t2;
      }
    }
  }

  if (timeron) {
    timer_stop(t_pinvr);
  }
}
