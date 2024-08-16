void init_array(int n, double x[n][n], double a[n][n], double b[n][n])
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      x[j][i] = ((double)(i * j) + 1.0) / (double)n;
      a[j][i] = ((double)(i * (j + 1)) + 2.0) / (double)n;
      b[j][i] = ((double)(i * (j + 2)) + 3.0) / (double)n;
    }
}
