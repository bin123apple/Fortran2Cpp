void kernel_trmm(int ni, double alpha, double a[100][100], double b[100][100])
{
    int i, j, k;
#pragma scop
 for (i = 1; i < ni; i++)
 for (j = 0; j < ni; j++)
 for (k = 0; k < i; k++)
 b[j][i] = b[j][i] + (alpha * a[k][i] * b[k][j]);
#pragma endscop
}
