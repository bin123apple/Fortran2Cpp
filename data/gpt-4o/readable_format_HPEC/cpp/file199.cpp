#include <stdio.h>

#define DATA_TYPE int
#define _PB_NI ni
#define _PB_NJ nj

void kernel_syrk(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, DATA_TYPE c[100][100], DATA_TYPE a[100][100]) 
{
    int i, j, k;
    
    for (i = 0; i < _PB_NI; i++)
        for (j = 0; j < _PB_NI; j++)
            c[j][i] *= beta;

    for (i = 0; i < _PB_NI; i++)
        for (j = 0; j < _PB_NI; j++)
            for (k = 0; k < _PB_NJ; k++)
                c[j][i] += alpha * a[k][i] * a[k][j];
}
