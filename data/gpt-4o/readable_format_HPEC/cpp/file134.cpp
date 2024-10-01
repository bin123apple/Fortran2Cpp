#include <stdio.h>
#include <omp.h>
int a[100], b[100];
int main()
{
 int i;
 int tmp, tmp2;
 for (i=0;i<100;i++)
 {
 a[i]=i+1;
 b[i]=i+1;
 }
#pragma omp parallel private(tmp)
 {
#pragma omp for
 for (i=0;i<100;i++)
 {
 tmp=a[i]+(i+1);
 a[i]=tmp;
 }
 }
#pragma omp parallel private(tmp2)
 {
#pragma omp for
 for (i=0;i<100;i++)
 {
 tmp2=b[i]+(i+1);
 b[i]=tmp2;
 }
 }
 printf ("%d   %d\n", a[49], b[49]);
 return 0;
}
