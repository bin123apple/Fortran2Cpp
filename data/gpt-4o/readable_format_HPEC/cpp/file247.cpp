void init_array(int nr, int nq, int np, double a[][nq][nr], double cFour[][np])
{
 int i, j, k;
 for (i = 0; i < nr; i++)
 for (j = 0; j < nq; j++)
 for (k = 0; k < np; k++)
 a[k][j][i] = ((double)(i) * (double)(j) + (double)(k)) / (double)(np);
 for (i = 0; i < np; i++)
 for (j = 0; j < np; j++)
 cFour[j][i] = ((double)(i) * (double)(j)) / np;
}
