```C++
void init_array(int ni, int nj, double alpha, double beta, double c[100][100], double a[100][100], double b[100][100])
{
  int i, j;
  alpha = 32412.0;
  beta = 2123.0;

  for(i = 0; i < ni; i++)
    for(j = 0; j < nj; j++)
    {
      c[j][i] = ((double) ((i) * (j))) / (double) ni;
      b[j][i] = ((double) ((i) * (j))) / (double) ni;
    }

  for(i = 0; i < nj; i++)
    for(j = 0; j < nj; j++)
      a[j][i] = ((double) ((i) * (j))) / (double) ni;
}
```
