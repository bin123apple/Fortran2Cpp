#include <stdio.h>
#include <omp.h>
double a[100][100], b[100][100];
int main() 
{
 int i, j;
#pragma omp parallel for collapse(2) default(none) shared(a)
 for (i=0;i<100;i++) {
  for (j=0;j<100;j++)
   a[i][j]=a[i][j]+1;
 }
#pragma omp parallel for collapse(2) default(shared)
 for (i=0;i<100;i++) {
  for (j=0;j<100;j++)
   b[i][j]=b[i][j]+1;
 }
 printf("a[50][50]=%f b[50][50]=%f
", a[50][50], b[50][50]);
 return 0;
}
