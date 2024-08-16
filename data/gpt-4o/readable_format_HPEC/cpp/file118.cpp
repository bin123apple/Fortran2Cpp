#include <stdio.h>
#include <omp.h>
int a[100][100];
int main()
{
 int i,j;
#pragma omp parallel for ordered(2)
 for(i=0;i<100;i++)
 for(j=0;j<100;j++)
 {
  a[i][j] = a[i][j]+1;
  #pragma omp ordered depend(sink:i-1,j) depend(sink:i,j-1)
  printf("test i = %d, j = %d
", i, j);
  #pragma omp ordered depend(source)
 }
 return 0;
}
