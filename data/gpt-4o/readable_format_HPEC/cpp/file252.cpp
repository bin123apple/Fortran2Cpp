#include <stdio.h>
#define DATA_PRINTF_MODIFIER "%f "

void print_array(int ni, int nl, float g[nl][ni]) {
 for (int i = 0; i < ni; i++) {
  for (int j = 0; j < nl; j++) {
   printf(DATA_PRINTF_MODIFIER, g[j][i]);
   if (((i * ni) + j) % 20 == 0)
    printf("
");
  }
 }
 printf("
");
}
