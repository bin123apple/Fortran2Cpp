#include <stdio.h>
#include <omp.h>

int main()
{
    int i, len=100, numNodes=len, numNodes2=0;
    int x[100];

    for (i=0; i<len; i++)
    {
        if (i%2 == 0)
            x[i] = 5;
        else
            x[i] = -5;
    }

#pragma omp parallel for
    for (i=numNodes-1; i>=0; i--)
    {
        if (x[i] <= 0)
        {
            #pragma omp atomic
            numNodes2--;
        }
    }

    printf("numNodes2 = %d\n", numNodes2);
    return 0;
}
