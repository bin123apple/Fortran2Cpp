void kernel_trisolv(int n , double a[][n], double x[n], double c[n])
{
 int i, j;
 for (i = 0; i < n; i++)
 {
 x[i] = c[i];
 for (j = 0; j < i; j++)
 x[i] = x[i] - (a[j][i] * x[j]);
 x[i] = x[i] / a[i][i];
 }
}
