#include <stdio.h>
#include <omp.h>

int main()
{
    int len = 1000;
    int a[len];
    a[0] = 2;
    #pragma omp parallel for
    for (int i = 0; i < len; i++)
    {
        a[i] = a[i]+a[0];
    }
    printf("a[500] = %d\n", a[500]);
    return 0;
}
