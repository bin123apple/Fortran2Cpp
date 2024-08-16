#include <stdio.h>

#define DATA_TYPE double
#define _PB_N 100

DATA_TYPE y[_PB_N][_PB_N];
DATA_TYPE sumArray[_PB_N][_PB_N];
DATA_TYPE beta[_PB_N];
DATA_TYPE alpha[_PB_N];
DATA_TYPE r[_PB_N];
DATA_TYPE outArray[_PB_N];

void kernel_durbin(int n) 
{
    int i, k;

    y[0][0] = r[0];
    beta[0] = 1;
    alpha[0] = r[0];
    for (k = 1; k < n; k++) {
        beta[k] = beta[k - 1] - (alpha[k -1] * alpha[k - 1] * beta[k - 1]);
        sumArray[k][0] = r[k];
        for (i = 0; i < k; i++) {
            sumArray[k][i + 1] = sumArray[k][i] + (r[k - i] * y[k - 1][i]);
        }
        alpha[k] = alpha[k] - (sumArray[k][k] * beta[k]);
        for (i = 0; i < k; i++) {
            y[k][i] = y[k - 1][i] + (alpha[k] * y[k - 1][k - i]);
        }
        y[k][k] = alpha[k];
    }
    for (i = 0; i < n; i++) {
        outArray[i] = y[n - 1][i];
    }
} 

int main()
{
    kernel_durbin(_PB_N);
    return 0;
}
