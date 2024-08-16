#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define MSIZE 200
#define MITS 1000
#define RELAXATION 1.0
#define ALPHA 0.0543

double u[MSIZE][MSIZE];
double f[MSIZE][MSIZE];
double uold[MSIZE][MSIZE];

void initialize() {
  double dx = 2.0 / (MSIZE - 1);
  double dy = 2.0 / (MSIZE - 1);

  //Initialize initial condition and RHS
  #pragma omp parallel for
  for (int i = 0; i < MSIZE; i++) {
    for (int j = 0; j < MSIZE; j++) {
      double xx = -1.0 + dx * i;
      double yy = -1.0 + dy * j;
      u[i][j] = 0.0;
      f[i][j] = -1.0 * ALPHA * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
    }
  }
}

int main() {
  initialize();
  return 0;
}
