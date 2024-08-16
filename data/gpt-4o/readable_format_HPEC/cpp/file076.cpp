#include <stdio.h>
float a[20][20];
int main()
{
 int i,j;
 for (i=0;i<20;i++)
 for (j=0;j<20;j++)
 a[i][j]=0.5;
#pragma omp parallel for private(j)
 for (i=0;i<19;i++)
 for (j=0;j<20;j++)
 a[i][j]=a[i][j]+a[i+1][j];
 printf ("a[10][10]=%f
", a[10][10]);
 return 0;
}
