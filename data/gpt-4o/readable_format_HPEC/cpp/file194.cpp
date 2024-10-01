#include <stdio.h>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d "

void print_array(int m, DATA_TYPE symmat[100][100]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      printf(DATA_PRINTF_MODIFIER, symmat[j][i]);
      if (((i * m) + j) % 20 == 0) {
        printf("\n");
      }
    }
  }
  printf("\n");
}
