void init_array(int n, double& alpha, double& beta, double a[][n], double u1[], double u2[], double v1[], double v2[], double w[], double x[], double y[], double z[]){
 alpha = 43532.0;
 beta = 12313.0;
 for (int i = 0; i < n; i++) {
 u1[i] = double(i);
 u2[i] = double(i) / n / 2.0;
 v1[i] = double(i) / n / 4.0;
 v2[i] = double(i) / n / 6.0;
 y[i] = double(i) / n / 8.0;
 z[i] = double(i) / n / 9.0;
 x[i] = 0.0;
 w[i] = 0.0;
 for (int j = 0; j < n; j++) {
 a[j][i] = (double(i) * double(j)) / double(n);
 }
 }
}
