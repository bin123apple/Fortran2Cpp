#include <iostream>
typedef int DATA_TYPE;
#define DATA_PRINTF_MODIFIER "%d "

void print_array(int n, DATA_TYPE y[]) {
 for (int i = 0; i < n; i++) {
  printf(DATA_PRINTF_MODIFIER, y[i]);
  if (i % 20 == 0) {
   printf("
");
  }
 }
}
