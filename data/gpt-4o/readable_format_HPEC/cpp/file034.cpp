#include <stdio.h>
#include <omp.h>

int main() {
    int x = 0, y = 2;
#pragma omp parallel
    {
#pragma omp single
        {
#pragma omp task shared(x)
            {
                x = x + 1;
            }
#pragma omp task shared(y)
            {
                y = y - 1;
            }
#pragma omp taskwait
            printf("x=%d
", x);
#pragma omp taskwait
            printf("y=%d
", y);
        }
    }
    return 0;
}
