#include <stdio.h>
#include <omp.h>

int main()
{
    int x = 0;
    int y;
    int tmp;

#pragma omp parallel num_threads(2)
    {
        int thrd = omp_get_thread_num();
        if (thrd == 0)
        {
#pragma omp critical
            x = 10;
#pragma omp flush(x)
#pragma omp atomic write
            y = 1;
        }
        else
        {
            tmp = 0;
            while (tmp == 0)
            {
#pragma omp atomic read
                tmp = x;
            }
#pragma omp critical
            printf("x = %d\n", x);
        }
    }
    return 0;
}
