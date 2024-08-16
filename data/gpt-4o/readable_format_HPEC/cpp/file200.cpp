void init_array(int n, double x1[], double x2[], double y1[], double y2[], double a[][n]) {
 for(int i = 0; i < n; ++i) {
  x1[i] = double(i) / double(n);
  x2[i] = (double(i) + 1.0) / double(n);
  y1[i] = (double(i) + 3.0) / double(n);
  y2[i] = (double(i) + 4.0) / double(n);
  for(int j = 0; j < n; ++j) {
   a[j][i] = (double(i) * double(j)) / double(n);
  }
 }
}
