#include <iostream>

using namespace std;

void add() {
  if (timeron) {
    timer_start(t_add);
  }

  for (int k = 1; k <= nz2; k++) {
    for (int j = 1; j <= ny2; j++) {
      for (int i = 1; i <= nx2; i++) {
        for (int m = 1; m <= 5; m++) {
          nu(m, i, j, k) = u(m, i, j, k) + rhs(m, i, j, k);
        }
      }
    }
  }

  if (timeron) {
    timer_stop(t_add);
  }
}

int main() {
  add();
  return 0;
}
