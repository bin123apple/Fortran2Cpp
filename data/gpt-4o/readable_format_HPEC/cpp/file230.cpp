void kernel_mvt(int n, double* x1, double* x2, double* y1, double* y2, double** a)
{
 int i, j;
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 x1[i] += a[j][i] * y1[j];
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 x2[i] += a[i][j] * y2[j];
}
