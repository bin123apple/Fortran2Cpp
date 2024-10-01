#include <stdio.h>
int main()
{
 int i, len = 100;
 int a[len], b[len];
 for (i=0; i<len; i++){
 a[i] = i+1;
 b[i] = i+2;
 }
#pragma omp simd
 for (i=0; i<len-1; i++)
 a[i+1] = a[i] + b[i];
 for (i=0; i<len; i++)
 printf("Values for i and a[i] are: %d %d\n", i+1, a[i]);
 return 0;
}
