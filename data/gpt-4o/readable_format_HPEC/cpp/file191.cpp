void init_array(int ni, int nj, double a[][100], double r[][100], double q[][100])
{
 int i, j;
 for (i = 0; i < ni; i++)
 for (j = 0; j < nj; j++)
 {
 a[j][i] = ((double)(i) * (double)(j)) / (double)ni;
 q[j][i] = ((double)(i) * (double)(j+1)) / (double)nj;
 }
 for (i = 0; i < ni; i++)
 for (j = 0; j < nj; j++)
 r[j][i] = ((double)(i) * (double)(j+2)) / (double)nj;
}
