void init_array(int ni, int nj, double alpha, double beta, double c[100][100], double a[100][100], double b[100][100])
{
 alpha = 32412.0;
 beta = 2123.0;

 for(int i = 0; i < ni; i++)
 for(int j = 0; j < nj; j++)
 {
 a[j][i] = (double(i) * double(j)) / double(ni);
 b[j][i] = (double(i) * double(j)) / double(ni);
 }

 for(int i = 0; i < ni; i++)
 for(int j = 0; j < ni; j++)
 {
 c[j][i] = (double(i) * double(j)) / double(ni);
 }
}
