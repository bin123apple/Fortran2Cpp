#include <stdio.h>
#include <omp.h>

float a[100][100];
float v[100];
float v_out[100];

void foo(){
    int i,j;
    float sum;
#pragma omp parallel for private(i,j,sum)
    for (i=0;i<100;i++){
        sum=0;
        for (j=0;j<100;j++){
            sum = sum + a[i][j]*v[j];
        }
        v_out[i] = sum;
    }
}

int main(){
    foo();
    return 0;
}
