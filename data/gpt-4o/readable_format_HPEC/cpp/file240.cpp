void kernel_adi(int tsteps, int n, float** x, float** a, float** b){
 for (int t = 0; t < tsteps; t++) {
 for (int i1 = 0; i1 < n; i1++) {
 for (int i2 = 1; i2 < n; i2++) {
 x[i2][i1] -= (x[i2 - 1][i1] * a[i2][i1]) / b[i2 - 1][i1];
 b[i2][i1] -= (a[i2][i1] * a[i2][i1]) / b[i2 - 1][i1];
 }
 }
 for (int i1 = 0; i1 < n; i1++) {
 x[n - 1][i1] /= b[n - 1][i1];
 }
 for (int i1 = 0; i1 < n; i1++) {
 for (int i2 = 0; i2 < n - 2; i2++) {
 x[n - i2 - 2][i1] = (x[n - i2 - 2][i1] - (x[n - i2 - 3][i1] * a[n - i2 - 3][i1])) / b[n - i2 - 3][i1];
 }
 }
 for (int i1 = 1; i1 < n; i1++) {
 for (int i2 = 0; i2 < n; i2++) {
 x[i2][i1] -= x[i2][i1 - 1] * a[i2][i1] / b[i2][i1 - 1];
 b[i2][i1] -= a[i2][i1] * a[i2][i1] / b[i2][i1 - 1];
 }
 }
 for (int i2 = 0; i2 < n; i2++) {
 x[i2][n - 1] /= b[i2][n - 1];
 }
 for (int i1 = 0; i1 < n - 2; i1++) {
 for (int i2 = 0; i2 < n; i2++) {
 x[i2][n - i1 - 2] = (x[i2][n - i1 - 2] - (x[i2][n - i1 - 3] * a[i2][n - i1 - 3])) / b[i2][n - i1 - 2];
 }
 }
 }
}
