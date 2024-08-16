void init_array(int n, double a[][n+1], double x[], double y[], double b[]) 
{
 for (int i = 0; i <= n; i++)
 {
  x[i] = double(i);
  y[i] = (double(i)/n/2.0) + 1.0;
  b[i] = (double(i)/n/2.0) + 42.0;
  for (int j = 0; j <= n; j++)
  {
   a[j][i] = (double(i) * double(j)) / double(n);
  }
 }
}
