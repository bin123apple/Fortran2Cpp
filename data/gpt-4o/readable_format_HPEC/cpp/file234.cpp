#include <stdio.h>
typedef double DATA_TYPE;

void init_array(DATA_TYPE &alpha, DATA_TYPE &beta, DATA_TYPE a[100][100], DATA_TYPE b[100][100], DATA_TYPE c[100][100], DATA_TYPE d[100][100], int ni, int nj, int nk, int nl)
{
    int i, j;
    alpha = 32412;
    beta = 2123;

    for(i = 0; i < ni; ++i)
        for(j = 0; j < nk; ++j)
            a[j][i] = double((i) * (j)) / ni;

    for(i = 0; i < nk; ++i)
        for(j = 0; j < nj; ++j)
            b[j][i] = double((i) * (j+1))/ nj;

    for(i = 0; i < nl; ++i)
        for(j = 0; j < nj; ++j)
            c[j][i] = double((i) * (j+2))/ nl;

    for(i = 0; i < ni; ++i)
        for(j = 0; j < nl; ++j)
            d[j][i] = double((i) * (j+1))/ nk;
}
