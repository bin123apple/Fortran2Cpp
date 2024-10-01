#include <stdio.h>
#include <omp.h>

int var[100];

int main()
{
    for(int i = 0; i < 100; i++)
    {
        var[i] = 1;
    }

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute parallel for simd safelen(16)
    for(int i = 16; i < 100; i++)
    {
        var[i] = var[i-16] + 1;
    }

    printf("%d\n", var[98]);

    return 0;
}
