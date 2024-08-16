#include <stdio.h>
float a[100][100], b[100][100], c[100][100];
int main()
{
 int i,j,l;
#pragma omp parallel for private(j, l)
 for (i=0;i<100;i++)
 for (l=0;l<100;l++)
 for (j=0;j<100;j++)
 c[i][j]+=a[i][l]*b[l][j];
 return 0;
}
