#include <stdio.h>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d "
void print_array(int n, DATA_TYPE x[])
{
 for(int i=0;i<n+1;i++)
 {
 printf(DATA_PRINTF_MODIFIER, x[i]);
 if(i % 20 == 0)
 printf("
");
 }
}
