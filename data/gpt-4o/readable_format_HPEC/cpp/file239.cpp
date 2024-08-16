void kernel_3mm(int ni, int nj, int nk, int nl, int nm, double** e, double** a, double** b, double** f, double** c, double** d, double** g)
{
 int i, j, k;

 // E := A*B
 for (i = 0; i < ni; i++)
 for (j = 0; j < nj; j++)
 {
 e[j][i] = 0.0;
 for (k = 0; k < nk; k++)
 e[j][i] += a[k][i] * b[j][k];
 }

 // F := C*D
 for (i = 0; i < nj; i++)
 for (j = 0; j < nl; j++)
 {
 f[j][i] = 0.0;
 for (k = 0; k < nm; k++)
 f[j][i] += c[k][i] * d[j][k];
 }

 // G := E*F
 for (i = 0; i < ni; i++)
 for (j = 0; j < nl; j++)
 {
 g[j][i] = 0.0;
 for (k = 0; k < nj; k++)
 g[j][i] += e[k][i] * f[j][k];
 }
}
