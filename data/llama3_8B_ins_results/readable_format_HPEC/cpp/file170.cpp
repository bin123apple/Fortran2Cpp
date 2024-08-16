#include <iostream>

void adi() {
  compute_rhs();
  txinvr();
  x_solve();
  y_solve();
  z_solve();
  add();
}

int main() {
  adi();
  return 0;
}
