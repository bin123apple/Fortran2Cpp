#include <stdio.h>
#include <omp.h>

int main()
{
    int m = 1;
    int n = 4;
    float b[4];

#pragma omp simd safelen(2)
    for (int i = m+1; i < n; i++)
    {
        b[i] = b[i-m] - 1.0;
    }

    printf("%f\n", b[3]);
    return 0;
}
