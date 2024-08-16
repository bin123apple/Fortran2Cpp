#include <stdio.h>
#include <stdlib.h>

float a[1000][1000];

int main(int argc, char* argv[])
{
    int i, j, len = 1000;
    if (argc > 1) {
        len = atoi(argv[1]);
        if (len <= 0) {
            printf("Error, invalid integer value.
");
            return 1;
        }
    } else {
        printf("No command line arguments provided.
");
    }

    for (i = 0; i < len; i++)
        for (j = 0; j < len; j++)
            a[i][j] = 0.5;

#pragma omp parallel for private(j)
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len; j++)
            a[i][j] = a[i][j] + a[i+1][j];

    printf("a[10][10] = %f
", a[10][10]);

    return 0;
}
