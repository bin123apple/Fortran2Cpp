#include <stdio.h>
#include <omp.h>

int main()
{
    int x = 2;

#pragma omp task shared(x) mergeable
    {
        x = x + 1;
    }
#pragma omp taskwait

    printf("x = %d\n", x);
    return 0;
}
