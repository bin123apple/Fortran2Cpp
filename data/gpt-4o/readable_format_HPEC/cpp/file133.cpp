#include <stdio.h>
#include <omp.h>
int main()
{
    int a[4], psum[4], sum, i;
#pragma omp parallel num_threads(2)
    {
#pragma omp for schedule(dynamic, 1)
        for (i = 0; i < 4; i++)
        {
            a[i] = i+1;
        }
#pragma omp single
        {
#pragma omp task
            {
#pragma omp task
                {
                  psum[1] = a[2]+a[3];
                }
                psum[0] = a[0]+a[1];
            }
#pragma omp taskwait
            sum = psum[1]+psum[0];
        }
    }
    printf("sum = %d
", sum);
    return 0;
}
