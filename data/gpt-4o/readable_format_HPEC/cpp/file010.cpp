#include <stdio.h>
#include <omp.h>

int main()
{
    int var[100];
    for(int i=0; i<100; i++)
        var[i] = 1;

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute parallel for
    for(int i=1; i<100; i++)
        var[i] = var[i-1]+1;

    printf("%d", var[99]);
    return 0;
}
