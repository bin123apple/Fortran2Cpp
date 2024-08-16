#include <stdio.h>
#include <omp.h>
int main()
{
 int i;
 int input[1000];
 int output[1000];
 int inLen = 1000;
 int outLen = 1;

 for (i=0; i<inLen; i++) {
   input[i] = i+1;
 }

#pragma omp parallel for
 for (i=0; i<inLen; i++) {
   output[outLen-1] = input[i];
   outLen++;
 }

 printf ("output[500]=%d
", output[499]);
 return 0;
}
