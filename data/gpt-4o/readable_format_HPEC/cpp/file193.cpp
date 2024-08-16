void init_array(int m, int n, double float_n, double dat[100][100])
{
 for (int i=0;i<m;i++)
 for (int j=0;j<n;j++)
 dat[j][i] = ((double)((i)*(j)))/double(m);
}
