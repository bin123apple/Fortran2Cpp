#include <stdio.h>
#include <omp.h>

int main()
{
    int len = 100;
    double a[len];

    for (int i = 0; i < len; i++)
        a[i] = (double)i / 2.0;

#pragma omp target map(tofrom: a[0:len])
#pragma omp teams num_teams(2)
    a[50] = a[50] * 2.0;

    printf("a[50]=%f\n", a[50]);

    return 0;
}
