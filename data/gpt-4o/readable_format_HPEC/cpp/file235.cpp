#include <stdio.h>
#define DATA_TYPE double

DATA_TYPE c[100][100];
DATA_TYPE w[100][100];
DATA_TYPE sumC[100][100][100];

void kernel_dynprog(int tsteps, int length, DATA_TYPE output)
{
    int i, j, iter, k;

    output = 0;

    for (iter = 0; iter < tsteps; iter++) {
        for (i = 0; i < length; i++) {
            for (j = 0; j < length; j++) {
                c[j][i] = 0;
            }
        }

        for (i = 0; i < length-1; i++) {
            for (j = i+1; j < length; j++) {
                sumC[i][j][i] = 0;
                for (k = i+1; k < j-1; k++) {
                    sumC[k][j][i] = sumC[k-1][j][i] + c[k][i] + c[j][k];
                }
                c[j][i] = sumC[j-1][j][i] + w[j][i];
            }
        }
        output = output + c[length-1][0];
    }
}
int main() {
    int tsteps = 10;
    int length = 100;
    DATA_TYPE output = 0.0;
    kernel_dynprog(tsteps, length, output);
    return 0;
}
