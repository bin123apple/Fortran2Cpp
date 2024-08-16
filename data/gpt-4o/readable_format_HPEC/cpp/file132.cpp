#include <stdio.h>
#include <omp.h>

int main()
{
    int x = 2;

#pragma omp task mergeable
    {
        x = x+1;
    }
#pragma omp taskwait

    printf ("x = %d
", x);
    return 0;
}
