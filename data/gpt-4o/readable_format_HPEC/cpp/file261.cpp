#include <iostream>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d"

void print_array(int n, DATA_TYPE x[][n]) 
{
 for (int i = 0; i < n; i++) 
 {
  for (int j = 0; j < n; j++) 
  {
   printf(DATA_PRINTF_MODIFIER, x[j][i]);
   if (((i * n) + j) % 20 == 0) 
   {
    printf("\n");
   }
  }
 }
 printf("\n");
}
