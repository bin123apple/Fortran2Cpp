#include <stdio.h>
#include <omp.h>

int main()
{
 int b[8], c[8], temp[8], a, i, j, k, val = 0;

 for (i=0;i<8;i++)
 {
   b[i] = 0;
   c[i] = 2;
   temp[i] = 0;
 }

 a = 2;

 #pragma omp target map(tofrom:b) map(to:c,temp,a) device(0)
 {
 #pragma omp parallel
 {
 for (i=0; i<100; i++)
 {
 #pragma omp for
 for (j=0; j<8; j++)
 temp[j] = b[j] + c[j];

 #pragma omp for
 for (j=7; j>=0; j--)
 b[j] = temp[j] * a;
 }
 }
 
 for (i=0; i<100; i++)
 {
 val += 2;
 val *= 2;
 }

 for (i=0; i<8; i++)
 {
 if (val != b[i])
 printf("%d, %d\n", b[i], val);
 }

 return 0;
}
