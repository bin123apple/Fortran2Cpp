void kernel_atax(int nx, int ny, double **a, double *x, double *y, double *tmp)
{
 int i, j;
#pragma scop
 for (i = 0; i < ny; i++)
 y[i] = 0.0;
 for (i = 0; i < nx; i++)
 {
 tmp[i] = 0.0;
 for (j = 0; j < ny; j++)
 tmp[i] = tmp[i] + (a[j][i] * x[j]);
 for (j = 0; j < ny; j++)
 y[j] = y[j] + a[j][i] * tmp[i];
 }
#pragma endscop
}
