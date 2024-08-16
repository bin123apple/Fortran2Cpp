#include <stdio.h>
int main()
{
 int i, len=100;
 int a[len];

 for (i=0;i<len;i++)
 a[i]=i+1;

#pragma omp parallel for
 for (i=0;i<len-1;i++)
 a[i+1]=a[i]+1;

 printf ("a[50]=%d
", a[50]);
 return 0;
}
