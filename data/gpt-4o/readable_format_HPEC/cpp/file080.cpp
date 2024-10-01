#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int i, j, n, m, len;
    double **b;
    len = 1000;
    if (argc > 1)
    {
        len = atoi(argv[1]);
    }
    n = m = len;
    b = new double*[n];
    for (i = 0; i < n; i++)
    {
        b[i] = new double[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            b[i][j] = 0.5;
        }
    }

    #pragma omp parallel for private(j)
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            b[i][j] = b[i-1][j-1];
        }
    }
    printf("b[500][500] = %.6f\n", b[500][500]);

    for (i = 0; i < n; i++)
    {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
