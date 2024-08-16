#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double errnm[5];

void error() {
  int i, j, k, m;
  double tmp;
  double u000ijk[5];

  for (m = 0; m < 5; m++) {
    errnm[m] = 0.0;
  }

  for (k = 1; k < nz-1; k++) {
    for (j = jst; j <= jend; j++) {
      for (i = ist; i <= iend; i++) {
        exact(i, j, k, u000ijk);
        for (m = 0; m < 5; m++) {
          tmp = (u000ijk[m] - u[i][j][k]);
          errnm[m] += tmp * tmp;
        }
      }
    }
  }

  for (m = 0; m < 5; m++) {
    errnm[m] = sqrt(errnm[m] / ((double)(nx0-2)*(ny0-2)*(nz0-2)));
  }

  cout << "RMS-norm of error in soln. to first pde  = " << errnm[0] << endl;
  cout << "RMS-norm of error in soln. to second pde = " << errnm[1] << endl;
  cout << "RMS-norm of error in soln. to third pde  = " << errnm[2] << endl;
  cout << "RMS-norm of error in soln. to fourth pde = " << errnm[3] << endl;
  cout << "RMS-norm of error in soln. to fifth pde  = " << errnm[4] << endl;
}

int main() {
  error();
  return 0;
}
