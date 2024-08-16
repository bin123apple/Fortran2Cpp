void kernel_lu(int n, float a[n][n]) 
{
  int i, j, k;
  
  for (k = 0; k < n; k++)
  {
    for (j = k + 1; j < n; j++)
    {
      a[j][k] = a[j][k] / a[k][k];
    }
    for (i = k + 1; i < n; i++)
    {
      for (j = k + 1; j < n; j++)
      {
        a[j][i] = a[j][i] - (a[k][i] * a[j][k]);
      }
    }
  }
}
