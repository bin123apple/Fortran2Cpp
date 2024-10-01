#include <iostream>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d "
void print_array(int n, DATA_TYPE a[100][100]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf(DATA_PRINTF_MODIFIER, a[j][i]);
      if (((i) * n + j) % 20 == 0) {
        printf("\n");
      }
    }
  }
  printf("\n");
}
