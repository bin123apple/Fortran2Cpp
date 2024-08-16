#include <stdio.h>
float b[100][100];
void foo()
{
 int i,j,n,m,len;
 len=100;
 n=len;
 m=len;
#pragma omp parallel for private(j)
 for (i=0;i<n;i++)
 for (j=1;j<m;j++)
 b[i][j]=b[i][j-1];
}
int main()
{
 foo();
 return 0;
}
