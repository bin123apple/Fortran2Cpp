#include <stdio.h>
#include <omp.h>

int main(){
    int len = 100;
    int tmp = 10;
    int a[len];

#pragma omp parallel for
    for(int i = 0; i < len; i++){
        a[i] = tmp;
        tmp = a[i] + i;
    }

    printf("a[50] = %d
", a[49]);

    return 0;
}
