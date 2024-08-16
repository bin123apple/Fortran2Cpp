#include <iostream>

using namespace std;

void add() {
  if (timeron) {
    timer_start(t_add);
  }

  for (int k = 1; k <= grid_points[2] - 2; k++) {
    for (int j = 1; j <= grid_points[1] - 2; j++) {
      for (int i = 1; i <= grid_points[0] - 2; i++) {
        for (int m = 1; m <= 5; m++) {
          u[m][i][j][k] += rhs[m][i][j][k];
        }
      }
    }
  }

  if (timeron) {
    timer_stop(t_add);
  }
}
