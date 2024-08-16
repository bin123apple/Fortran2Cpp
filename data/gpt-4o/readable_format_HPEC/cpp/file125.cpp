#include <stdio.h>
float b[100][100];
int main()
{
 int i,j;
 for (i=0;i<100;i++)
 for (j=0;j<100;j++)
 b[i][j]=i*j;
 for (i=1;i<100;i++)
 {
 #pragma omp parallel for
 for (j=1;j<100;j++)
 b[i][j]=b[i-1][j-1];
 }
 return 0;
}
