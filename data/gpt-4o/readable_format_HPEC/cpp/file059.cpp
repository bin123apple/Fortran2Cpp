#include <stdio.h>
#include <omp.h>

int a[100], b[100][100], c[100];

int main()
{
 int len=100;
 int i,j;
 for(i=0; i<len; i++)
 {
  for(j=0; j<len; j++)
  {
   b[i][j]=1;
  }
  a[i]=1;
  c[i]=0;
 }

#pragma omp target map(to:a,b) map(tofrom:c) device(0)
#pragma omp teams distribute parallel for
 for(i=0; i<len; i++)
 {
  for(j=0; j<len; j++)
  {
   c[i]=c[i]+a[j]*b[i][j];
  }
 }

 for(i=0; i<len; i++)
 {
  if(c[i]!=len)
  {
   printf("%d
", c[i]);
  }
 }

 return 0;
}
