#include <stdio.h>
float a[20][20];
int main() {
 int i,j;
 for (i=0;i<20;i++)
 for (j=0;j<20;j++)
 a[i][j]=0.0;
 for (i=0;i<19;i++)
 #pragma omp parallel for
 for (j=0;j<20;j++)
 a[i][j]=a[i][j]+a[i+1][j];
 return 0;
}
