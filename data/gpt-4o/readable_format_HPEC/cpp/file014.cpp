#include <stdio.h>
#include <omp.h>

int main()
{
    long long int num_steps = 2000000000;
    double x, pi = 0.0, interval_width = 1.0/num_steps;

#pragma omp parallel for reduction(+:pi) private(x)
    for (long long int i = 0; i < num_steps; i++) {
        x = (i + 0.5) * interval_width;
        pi = pi + 1.0 / (x*x + 1.0);
    }

    pi = pi * 4.0 * interval_width;

    printf("PI = %.20f
", pi);
    return 0;
}
