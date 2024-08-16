#include <iostream>
#include <cmath>

void initArray(int length, double** c, double** w) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      c[j][i] = (i * j - 1) % 2;
      w[j][i] = (double((i - 1) - (j - 1))) / length;
    }
  }
}
