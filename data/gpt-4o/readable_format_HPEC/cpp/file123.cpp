#include <stdio.h>
#include <omp.h>
float b[1000][1000];
int main()
{
    int i, j, len = 1000;
    #pragma omp parallel for private(j)
    for (i = 0; i < len; i++)
        for (j = 1; j < len; j++)
            b[i][j] = b[i][j-1];
    printf("b[500][500] = %.6f\n", b[500][500]);
    return 0;
}
