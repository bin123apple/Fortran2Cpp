#include <stdio.h>
int a[100];
int main()
{
 int i;
#pragma omp parallel for
 for (i=0;i<100;i++)
 a[i]=a[i]+1;
 return 0;
}
