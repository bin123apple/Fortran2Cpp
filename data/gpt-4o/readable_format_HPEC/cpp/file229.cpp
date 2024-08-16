void init_array(int n, double alpha, double a[][n], double b[][n])
{
 alpha = 32412.0;
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 {
 a[j][i] = ((double)(i) * (double)(j)) / n;
 b[j][i] = ((double)(i) * (double)(j)) / n;
 }
}
