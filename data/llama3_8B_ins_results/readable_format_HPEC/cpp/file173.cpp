#include <iostream>
#include <vector>

void comm3(std::vector<std::vector<std::vector<double>>>& u, int n1, int n2, int n3, int kk) {
  if (timeron) {
    timer_start(T_comm3);
  }

  for (int i3 = 2; i3 <= n3 - 1; ++i3) {
    for (int i2 = 2; i2 <= n2 - 1; ++i2) {
      u[0][i2][i3] = u[n1 - 1][i2][i3];
      u[n1][i2][i3] = u[1][i2][i3];
    }
  }

  for (int i1 = 1; i1 <= n1; ++i1) {
    u[i1][0][i3] = u[i1][n2 - 1][i3];
    u[i1][n2][i3] = u[i1][1][i3];
  }

  for (int i2 = 1; i2 <= n2; ++i2) {
    for (int i1 = 1; i1 <= n1; ++i1) {
      u[i1][i2][0] = u[i1][i2][n3 - 1];
      u[i1][i2][n3] = u[i1][i2][1];
    }
  }

  if (timeron) {
    timer_stop(T_comm3);
  }
}

int main() {
  // Initialize u, n1, n2, n3, and kk
  //...

  comm3(u, n1, n2, n3, kk);

  return 0;
}
