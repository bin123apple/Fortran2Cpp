#include <stdio.h>
#include <omp.h>

int main()
{
    int var = 0;
    int i;
    
    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute parallel for
    for (i = 0; i < 100; i++)
    {
        var = var+1;
    }
    
    printf("%d
", var);
    return 0;
}
