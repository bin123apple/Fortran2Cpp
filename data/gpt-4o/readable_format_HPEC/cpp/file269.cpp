#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("No command line arguments provided.
");
        return 0;
    }

    int n = atoi(argv[1]);
    int m = n;
    double b[n][m];

    if(n == 0)
    {
        printf("Error, invalid integer value.
");
        return 0;
    }

#pragma omp parallel for
    for(int j = 1; j < n; j++)
        for(int i = 0; i < m; i++)
            b[i][j] = b[i][j-1];

    printf("b[49][49]=%f
",b[49][49]);

    return 0;
}
