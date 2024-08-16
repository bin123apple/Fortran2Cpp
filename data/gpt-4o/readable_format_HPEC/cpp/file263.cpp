void init_array(int ni, int nj, int nk, int nl, int nm, double a[nk][ni], double b[nj][nk], double c[nm][nj], double d[nl][nm]) {
 int i, j;

 for (i = 0; i < ni; i++)
 for (j = 0; j < nk; j++)
 a[j][i] = (double)(i * j) / ni;
 
 for (i = 0; i < nk; i++)
 for (j = 0; j < nj; j++)
 b[j][i] = (double)(i * j) / nj;

 for (i = 0; i < nj; i++)
 for (j = 0; j < nm; j++)
 c[j][i] = (double)(i * (j+2)) / nl;

 for (i = 0; i < nm; i++)
 for (j = 0; j < nl; j++)
 d[j][i] = (double)(i * (j+1)) / nk;
}
