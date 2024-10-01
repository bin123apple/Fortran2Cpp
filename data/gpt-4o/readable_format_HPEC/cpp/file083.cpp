#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    int i, len = 100;
    int *a;
    int *b;

    if (argc == 1) 
    {
        printf("No command line arguments provided.\n");
        return 0;
    }

    len = atoi(argv[1]); 

    a = (int *)malloc(len * sizeof(int));
    b = (int *)malloc(len * sizeof(int));

    for (i = 0; i < len; i++)
    {
        a[i] = i;
        b[i] = i + 1;
    }

#pragma omp simd
    for (i = 0; i < len - 1; i++)
        a[i + 1] = a[i] + b[i];

    for (i = 0; i < len; i++)
        printf("Values for i and a[i] are: %d %d\n", i, a[i]);

    free(a);
    free(b);

    return 0;
}
