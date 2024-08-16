#include <stdio.h>
#include <omp.h>

int main()
{
    double a[100], b[100], c[100];
    int len = 100;
    int i, j;

    for (i = 0; i < len; i++)
    {
        a[i] = (double)i / 2.0;
        b[i] = (double)i / 3.0;
        c[i] = (double)i / 7.0;
    }

    #pragma omp parallel for private(j)
    for (i = 0; i < len; i++)
    {
        j = i;
        c[j] = c[j] + a[i]*b[i];
    }

    //printf("c[50] = %f
", c[50]);

    return 0;
}
