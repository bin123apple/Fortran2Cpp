#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv)
{
    int len = 100;
    int numNodes, numNodes2 = 0;
    int *x;
    int i;

    if (argc == 1)
    {
        printf("No command line arguments provided.\n");
        return 1;
    }

    len = atoi(argv[1]);

    x = (int *)malloc(len * sizeof(int));

    numNodes = len;

    for (i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            x[i] = 5;
        }
        else
        {
            x[i] = -5;
        }
    }

#pragma omp parallel for
    for (i = numNodes - 1; i >= 0; i--)
    {
        if (x[i] <= 0)
        {
            numNodes2--;
        }
    }

    printf("numNodes2 = %d\n", numNodes2);

    free(x);

    return 0;
}
