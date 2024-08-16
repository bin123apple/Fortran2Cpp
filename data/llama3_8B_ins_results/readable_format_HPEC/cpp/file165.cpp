#include <iostream>
#include <vector>

using namespace std;

void sparse(double* a, int* colidx, int* rowstr, int n, int nz, double* aelt, int* firstrow, int* lastrow, double* v, int* iv, int* nzloc, double rcond, double shift) {
  int i, j, jcol, k, kk, nzrow;
  double xi, size, scale, ratio, va;

  int nrows = *lastrow - *firstrow + 1;
  int j1 = 1;
  int j2 = *ihigh + 1;

  for (j = j1; j <= j2; j++) {
    rowstr[j] = 0;
  }

  for (i = 1; i <= n; i++) {
    int nza = 1;
    for (nza = 1; nza <= *arow[i]; nza++) {
      j = *acol[nza][i];
      if (j >= *ilow && j <= *ihigh) {
        j++;
        rowstr[j] = rowstr[j] + *arow[i];
      }
    }
  }

  if (*myid == 0) {
    rowstr[1] = 1;
    j1 = 1;
  }
  for (j = j1 + 1; j <= j2; j++) {
    rowstr[j] = rowstr[j] + rowstr[j - 1];
  }
  if (*myid < *num_threads) {
    *last_n[*myid] = rowstr[j2];
  }

  int nzrow = 0;
  if (*myid < *num_threads) {
    for (i = 0; i < *myid; i++) {
      nzrow += *last_n[i];
    }
  }
  if (nzrow > 0) {
    for (j = j1; j <= j2; j++) {
      rowstr[j] = rowstr[j] + nzrow;
    }
  }

  int nza = rowstr[nrows + 1] - 1;

  if (nza > nz) {
    cout << "Space for matrix elements exceeded in sparse" << endl;
    cout << "nza, nzmax = " << nza << ", " << nz << endl;
    exit(1);
  }

  for (j = *ilow; j <= *ihigh; j++) {
    for (k = rowstr[j]; k < rowstr[j + 1] - 1; k++) {
      v[k] = 0.0;
      iv[k] = 0;
    }
    nzloc[j] = 0;
  }

  size = 1.0;
  ratio = pow(*rcond, 1.0 / *n);

  for (i = 1; i <= n; i++) {
    int nza = 1;
    for (nza = 1; nza <= *arow[i]; nza++) {
      j = *acol[nza][i];
      if (j < *ilow || j > *ihigh) continue;
      scale = size * *aelt[nza][i];
      for (nzrow = 1; nzrow <= *arow[i]; nzrow++) {
        jcol = *acol[nzrow][i];
        va = *aelt[nzrow][i] * scale;
        if (jcol == j && j == i) {
          va += *rcond - *shift;
        }
        for (k = rowstr[j]; k < rowstr[j + 1] - 1; k++) {
          if (iv[k] > jcol) {
            for (kk = rowstr[j + 1] - 2; kk >= k; kk--) {
              if (iv[kk] > 0) {
                v[kk + 1] = v[kk];
                iv[kk + 1] = iv[kk];
              }
            }
            iv[k] = jcol;
            v[k] = 0.0;
            break;
          } else if (iv[k] == 0) {
            iv[k] = jcol;
            break;
          } else if (iv[k] == jcol) {
            nzloc[j]++;
            break;
          }
        }
        v[k] += va;
      }
    }
  }

  size *= ratio;

  for (j = *ilow + 1; j <= *ihigh; j++) {
    nzloc[j] += nzloc[j - 1];
  }
  if (*myid < *num_threads) {
    *last_n[*myid] = nzloc[*ihigh];
  }

  nzrow = 0;
  if (*myid < *num_threads) {
    for (i = 0; i < *myid; i++) {
      nzrow += *last_n[i];
    }
  }
  if (nzrow > 0) {
    for (j = *ilow; j <= *ihigh; j++) {
      nzloc[j] += nzrow;
    }
  }

  for (j = 1; j <= nrows; j++) {
    if (j > 1) {
      j1 = rowstr[j] - nzloc[j - 1];
    } else {
      j1 = 1;
    }
    j2 = rowstr[j + 1] - nzloc[j] - 1;
    nza = rowstr[j];
    for (k = j1; k <= j2; k++) {
      a[k] = v[nza];
      colidx[k] = iv[nza];
      nza++;
    }
  }

  for (j = 2; j <= nrows + 1; j++) {
    rowstr[j] = rowstr[j] - nzloc[j - 1];
  }
  nza = rowstr[nrows + 1] - 1;

  return;
}

int main() {
  // Initialize variables
  //...

  // Call the sparse function
  sparse(a, colidx, rowstr, n, nz, aelt, firstrow, lastrow, v, iv, nzloc, rcond, shift);

  //...
  return 0;
}
