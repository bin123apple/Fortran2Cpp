#include <iostream>
#include <cmath>

using namespace std;

void error_norm(double* u_exact, double* u, double* grid_points, double* dnzm1, double* dnym1, double* dnxm1) {
  double xi, eta, zeta, add;
  for (int m = 0; m < 5; m++) {
    u_exact[m] = 0.0;
  }
  for (int k = 0; k < grid_points[2]-1; k++) {
    for (int j = 0; j < grid_points[1]-1; j++) {
      zeta = k * dnzm1;
      eta = j * dnym1;
      for (int i = 0; i < grid_points[0]-1; i++) {
        xi = i * dnxm1;
        exact_solution(xi, eta, zeta, u_exact);
        for (int m = 0; m < 5; m++) {
          add = u[m][i][j][k] - u_exact[m];
          u[m][i][j][k] = add * add;
        }
      }
    }
  }
  for (int m = 0; m < 5; m++) {
    for (int d = 0; d < 3; d++) {
      u[m][0][0][0] /= (grid_points[d]-2);
    }
  }
  for (int m = 0; m < 5; m++) {
    u[m][0][0][0] = sqrt(u[m][0][0][0]);
  }
}

void rhs_norm(double* u, double* grid_points) {
  double add;
  for (int m = 0; m < 5; m++) {
    u[m][0][0][0] = 0.0;
  }
  for (int k = 1; k < grid_points[2]-2; k++) {
    for (int j = 1; j < grid_points[1]-2; j++) {
      for (int i = 1; i < grid_points[0]-2; i++) {
        for (int m = 0; m < 5; m++) {
          add = rhs(m, i, j, k);
          u[m][i][j][k] += add * add;
        }
      }
    }
  }
  for (int m = 0; m < 5; m++) {
    for (int d = 0; d < 3; d++) {
      u[m][0][0][0] /= (grid_points[d]-2);
    }
  }
  for (int m = 0; m < 5; m++) {
    u[m][0][0][0] = sqrt(u[m][0][0][0]);
  }
}

// Note: You will need to implement the exact_solution and rhs functions
// These are not provided in the original Fortran code
