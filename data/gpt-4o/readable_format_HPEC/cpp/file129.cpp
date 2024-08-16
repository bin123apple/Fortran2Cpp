#include <unistd.h>
#include <stdio.h>

#if (_OPENMP<201511)
#error "An OpenMP 4.5 compiler is needed to compile this test."
#endif

int main()
{
    int result = 0;
#pragma omp parallel
    {
#pragma omp single
        {
#pragma omp taskgroup
            {
#pragma omp task
                {
                    sleep(3);
                    result = 1;
                }
            }
#pragma omp task
            {
                result = 2;
            }
        }
    }
    printf("result = %d
", result);
    return 0;
}
