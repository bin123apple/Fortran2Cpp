#include <stdio.h>
#include <omp.h>

int main() {
    int i, j;
    double u[100][100], temp, getSum = 0.0;

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            u[i][j] = 0.5;
        }
    }

    #pragma omp parallel for private(temp, i, j)
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            temp = u[i][j];
            getSum = getSum + temp * temp;
        }
    }
    
    printf("sum = %f
", getSum);
    
    return 0;
}
