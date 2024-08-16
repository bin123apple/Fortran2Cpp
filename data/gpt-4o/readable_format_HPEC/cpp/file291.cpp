void kernel_seidel(int tsteps, int n, double a[n][n])
{
    int i, t, j;
    #pragma scop
    for (t = 1; t <= tsteps; t++)
        for (i = 1; i < n-1; i++)
            for (j = 1; j < n-1; j++)
                a[j][i] = (a[j - 1][i - 1] + a[j][i - 1] + a[j + 1][i - 1] +
                           a[j - 1][i] + a[j][i] + a[j + 1][i] +
                           a[j - 1][i + 1] + a[j][i + 1] +
                           a[j + 1][i + 1])/9.0;
    #pragma endscop
}
