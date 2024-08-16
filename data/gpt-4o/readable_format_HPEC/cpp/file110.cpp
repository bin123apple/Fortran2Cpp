#include <stdio.h>
int a[2000];
int main()
{
 int i;
 for (i=0;i<2000;i++)
 a[i]=i+1;
#pragma omp parallel for
 for (i=0;i<1000;i++)
 a[2*i]=a[i]+1;
 printf ("a[1002]=%d", a[1002]);
 return 0;
}
