#include <stdio.h>
#include <omp.h>

int main()
{
 int a = 2, val = 0;
 int b[8], c[8], temp[8];

 for (int i = 0; i < 8; i++) {
    b[i] = 0;
    c[i] = 2;
    temp[i] = 0;
 }

#pragma omp target map(tofrom:b) map(to:c,temp,a) device(0)
#pragma omp teams
 for (int i = 0; i < 100; i++) {
    #pragma omp distribute
    for (int j = 0; j < 8; j++)
        temp[j] = b[j] + c[j];

    #pragma omp distribute
    for (int j = 7; j >= 0; j--)
        b[j] = temp[j]*a;
 }

 for (int i = 0; i < 100; i++) {
    val = val + 2;
    val = val * 2;
 }

 for (int i = 0; i < 8; i++) {
    if (val != b[i])
        printf("%d %d
", b[i], val);
 }

 return 0;
}
