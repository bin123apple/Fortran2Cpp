#include <stdio.h>
#include <omp.h>

double x;
int y;

int main() {
#pragma omp parallel
    {
#pragma omp single copyprivate(x, y)
        {
            x = 1.0;
            y = 1;
        }
    }
    printf("x = %.1f  y = %d
", x, y);
    return 0;
}
