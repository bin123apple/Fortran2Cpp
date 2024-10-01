#include <iostream>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d"
void print_array(DATA_TYPE a[100][100][100], int nr, int nq, int np)
{
    for(int i=0;i<nr;i++)
        for(int j=0;j<nq;j++)
            for(int k=0;k<np;k++)
            {
                printf(DATA_PRINTF_MODIFIER, a[k][j][i]);
                if ((i % 20) == 0)
                    printf("\n");
            }
    printf("\n");
}
