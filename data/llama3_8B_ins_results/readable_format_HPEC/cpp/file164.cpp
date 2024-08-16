#include <iostream>
#include <cmath>

using namespace std;

void conj_grad(double& rnorm) {
  int j;
  int cgit, cgitmax;
  int k;
  double d, sum, rho, rho0, alpha, beta, suml;

  cgitmax = 25;

  rho = 0.0;
  sum = 0.0;

  for (j = 1; j <= naa + 1; j++) {
    q[j] = 0.0;
    z[j] = 0.0;
    r[j] = x[j];
    p[j] = r[j];
  }

  for (j = 1; j <= lastcol - firstcol + 1; j++) {
    rho += r[j] * r[j];
  }

  for (cgit = 1; cgit <= cgitmax; cgit++) {
    rho0 = rho;
    d = 0.0;
    rho = 0.0;

    for (j = 1; j <= lastrow - firstrow + 1; j++) {
      suml = 0.0;
      for (k = rowstr[j]; k < rowstr[j + 1]; k++) {
        suml += a[k] * p[colidx[k]];
      }
      q[j] = suml;
    }

    for (j = 1; j <= lastcol - firstcol + 1; j++) {
      d += p[j] * q[j];
    }

    alpha = rho0 / d;

    for (j = 1; j <= lastcol - firstcol + 1; j++) {
      z[j] += alpha * p[j];
      r[j] -= alpha * q[j];
      rho += r[j] * r[j];
    }

    beta = rho / rho0;

    for (j = 1; j <= lastcol - firstcol + 1; j++) {
      p[j] = r[j] + beta * p[j];
    }
  }

  for (j = 1; j <= lastrow - firstrow + 1; j++) {
    suml = 0.0;
    for (k = rowstr[j]; k < rowstr[j + 1]; k++) {
      suml += a[k] * z[colidx[k]];
    }
    r[j] = suml;
  }

  for (j = 1; j <= lastcol - firstcol + 1; j++) {
    suml = x[j] - r[j];
    sum += suml * suml;
  }

  rnorm = sqrt(sum);
}

int main() {
  // Initialize variables
  //...

  conj_grad(rnorm);

  // Use the result
  cout << "rnorm: " << rnorm << endl;

  return 0;
}
