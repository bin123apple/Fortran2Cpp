#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main()
{
    int i = 0, j, k;
#pragma omp parallel
    {
#pragma omp single
        {
#pragma omp task depend(out : i)
            {
                sleep(3);
                i = 1;
            }
#pragma omp task depend(in : i)
            {
                j = i;
            }
#pragma omp task depend(in : i)
            {
                k = i;
            }
        }
    }
    printf("j = %d  k = %d\n", j, k);
    if (j != 1 || k != 1)
    {
        printf("Race Condition\n");
    }
    return 0;
}
