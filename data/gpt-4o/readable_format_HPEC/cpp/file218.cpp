#include <iostream>
#define DATA_PRINTF_MODIFIER "%d "

void print_array(int n, int path[][100])
{
 for(int i=0; i<n; i++)
 {
  for(int j=0; j<n; j++)
  {
   printf(DATA_PRINTF_MODIFIER, path[j][i]);
   if (((i * n) + j) % 20 == 0) 
   {
    printf("
");
   }
  }
 }
 printf("
");
}
