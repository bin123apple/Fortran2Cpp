#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
 int len = 1000;
 int *a = (int*)malloc(len*sizeof(int));
 int i;

 if(argc == 1)
 {
 printf("No command line arguments provided.
");
 return 0;
 }

 if(argc >= 2)
 {
 len = atoi(argv[1]);
 if(len <= 0)
 {
 printf("Error, invalid integer value.
");
 return 0;
 }
 }

 a[0] = 2;

#pragma omp parallel for
 for(i=0; i<len; i++)
 a[i] = a[i] + a[0];

 printf("a[0] = %d
", a[0]);

 free(a);
 return 0;
}
