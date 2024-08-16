void kernel_jacobi1d(int tsteps, int n, float* a, float* b)
{
 int i, t, j;
 for (t = 0; t < tsteps; t++)
 {
  for (i = 1; i < n-1; i++)
   b[i] = 0.33333 * (a[i - 1] + a[i] + a[i + 1]);
  for (j = 1; j < n-1; j++)
   a[j] = b[j];
 }
}
