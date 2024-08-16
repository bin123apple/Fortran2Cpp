void init_array(int n, double a[n][n]) 
{
 for(int i = 0; i < n; i++)
 for(int j = 0; j < n; j++)
 a[j][i] = ((double(i - 1) * double(j + 1)) + 2.0) / n;
}
