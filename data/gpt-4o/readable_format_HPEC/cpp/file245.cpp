void init_array(int n, double a[][n], double x[], double c[]) {
  int i, j;
  for (i = 0; i < n; i++) {
    c[i] = double(i) / double(n);
    x[i] = double(i) / double(n);
    for (j = 0; j < n; j++) {
      a[j][i] = (double(i) * double(j)) / double(n);
    }
  }
}
