#include <stdio.h>
int a[100];
int main()
{
 int i,tmp;
 for (i=0;i<100;i++)
 a[i]=i+1;

#pragma omp parallel for private(tmp)
 for (i=0;i<100;i++)
 {
  tmp=a[i]+i+1;
  a[i]=tmp;
 }

 printf ("a[50]=%d
", a[50]);
 return 0;
}
