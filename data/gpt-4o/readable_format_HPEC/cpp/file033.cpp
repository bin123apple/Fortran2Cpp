#include <stdio.h>
#include <omp.h>

int main() {
    int len = 1000;
    int b = 5;
    int error;
    int a[len];
    for (int i = 0; i < len; i++) {
        a[i] = i + 1;
    }
    #pragma omp parallel shared(b, error)
    {
        #pragma omp parallel
        {
            #pragma omp for nowait
            for (int i = 0; i < len; i++) {
                a[i] = b + a[i] * 5;
            }
            #pragma omp single
            {
                error = a[9] + 1;
            }
        }
    }
    printf("error = %d\n", error);
    return 0;
}
