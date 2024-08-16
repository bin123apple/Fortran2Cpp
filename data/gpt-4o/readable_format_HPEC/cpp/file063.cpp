#include <stdio.h>
#include <omp.h>

int main()
{
    int len = 1000;
    int a[len];

    for (int i = 0; i < len; i++)
        a[i] = i+1;

    #pragma omp target map(a)
    {
        #pragma omp parallel for
        for (int i = 0; i < len-1; i++)
            a[i] = a[i+1] + 1;
    }

    for (int i = 0; i < len; i++)
        printf("Values for i and a[i] are: %d %d
", i+1, a[i]);

    return 0;
}
