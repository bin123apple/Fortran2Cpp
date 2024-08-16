#include <stdio.h>
int a[1000];
int main()
{
 int i;
 for (i=0; i<1000; i++)
 a[i]=i;
#pragma omp parallel for
 for (i=0; i<999; i++)
 a[i]=a[i+1]+1;
 printf ("a[500]=%d
", a[500]);
 return 0;
}
