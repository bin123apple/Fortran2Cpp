#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char* argv[])
{
 int i, tmp;
 int len = 100;
 if (argc == 1) {
 printf("No command line arguments provided.
");
 return 0;
 }
 len = atoi(argv[1]);
 if (len == 0) {
 printf("Error, invalid integer value.
");
 return 0;
 }
 int a[len];
 for (i=0;i<len;i++)
 a[i] = i+1;
#pragma omp parallel for private(tmp)
 for (i=0;i<len;i++)
 {
 tmp = a[i] + i+1;
 a[i] = tmp;
 }
 printf ("a[50]=%d
", a[50]);
 return 0;
}
