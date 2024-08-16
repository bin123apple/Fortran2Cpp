#include <iostream>
#include <cmath>

using namespace std;

void tzetar() {
  // Declare variables
  int i, j, k;
  double t1, t2, t3, ac, xvel, yvel, zvel, r1, r2, r3, r4, r5, btuz, ac2u, uzik1;

  // Check if timer is on
  if (timeron) {
    timer_start(t_tzetar);
  }

  // Loop over indices
  for (k = 1; k <= nz2; k++) {
    for (j = 1; j <= ny2; j++) {
      for (i = 1; i <= nx2; i++) {

        // Assign values
        xvel = us(i, j, k);
        yvel = vs(i, j, k);
        zvel = ws(i, j, k);
        ac = speed(i, j, k);

        // Calculate ac2u
        ac2u = ac * ac;

        // Assign rhs values
        r1 = rhs(1, i, j, k);
        r2 = rhs(2, i, j, k);
        r3 = rhs(3, i, j, k);
        r4 = rhs(4, i, j, k);
        r5 = rhs(5, i, j, k);

        // Assign u and btuz values
        uzik1 = u(1, i, j, k);
        btuz = bt * uzik1;

        // Calculate t1, t2, and t3
        t1 = btuz / ac * (r4 + r5);
        t2 = r3 + t1;
        t3 = btuz * (r4 - r5);

        // Update rhs values
        rhs(1, i, j, k) = t2;
        rhs(2, i, j, k) = -uzik1 * r2 + xvel * t2;
        rhs(3, i, j, k) = uzik1 * r1 + yvel * t2;
        rhs(4, i, j, k) = zvel * t2 + t3;
        rhs(5, i, j, k) = uzik1 * (-xvel * r2 + yvel * r1) + qs(i, j, k) * t2 + c2iv * ac2u * t1 + zvel * t3;
      }
    }
  }

  // Check if timer is on
  if (timeron) {
    timer_stop(t_tzetar);
  }
}
