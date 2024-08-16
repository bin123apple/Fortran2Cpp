void init_array(int n, double path[][100])
{
  int i, j;
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      path[j][i] = (double(i * j))/ double(n);
    }
  }
}
