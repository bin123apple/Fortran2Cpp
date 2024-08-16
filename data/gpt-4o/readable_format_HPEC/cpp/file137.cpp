#include <stdio.h>
#include <omp.h>

int main()
{
    int var = 0;
    int sum1 = 0;
    int sum2 = 0;

    #pragma omp parallel reduction(+: var)
    {
        #pragma omp for schedule(static) reduction(+: sum1)
        for(int i = 0; i < 5; i++)
        {
            sum1 = sum1 + i;
        }

        #pragma omp for schedule(static) reduction(+: sum2)
        for(int i = 0; i < 5; i++)
        {
            sum2 = sum2 + i;
        }

        var = sum1 + sum2;
    }

    printf("var = %d", var);
    return 0;
}
