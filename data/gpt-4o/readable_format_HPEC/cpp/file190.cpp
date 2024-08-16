void init_array(int ni, int nj, double alpha, double beta, double** c, double** a)
{
 alpha = 32412;
 beta = 2123;
 for (int i = 0; i < ni; i++)
 {
 for (int j = 0; j < nj; j++)
 {
 a[j][i] = ((double)(i) * (double)(j)) / (double)ni;
 }
 for (int j = 0; j < ni; j++)
 {
 c[j][i] = ((double)(i) * (double)(j)) / (double)ni;
 }
 }
}
