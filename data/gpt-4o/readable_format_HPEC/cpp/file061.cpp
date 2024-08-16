#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 1;

#pragma omp parallel sections
    {
#pragma omp section
        {
#pragma omp critical(name)
            {
#pragma omp parallel
                {
#pragma omp single
                    i += 1;
                }
            }
        }
    }

    printf("i = %d
", i);
    return 0;
}
