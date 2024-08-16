#include <stdio.h>
#include <omp.h>

int main()
{
    int len = 1000;
    int sum = 0;
    int sum0 = 0;

#pragma omp threadprivate(sum0)

#pragma omp parallel copyin(sum0)
    {
#pragma omp for
        for(int i = 0; i < len; i++)
        {
            sum0 += i+1;
        }

#pragma omp critical
        sum += sum0;
    }

    int sum1 = 0;
    for(int i = 0; i < len; i++)
    {
        sum1 += i+1;
    }

    printf("sum = %d, sum1 = %d
", sum, sum1);

    return 0;
}
