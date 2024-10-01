void print_array(int ni, int c[100][100]) {
  int i, j;
  for(i = 0; i < ni; i++) {
    for(j = 0; j < ni; j++) {
      printf(DATA_PRINTF_MODIFIER, c[j][i]);
      if ((i * ni + j) % 20 == 0) {
        printf("\n");
      }
    }
  }
  printf("\n");
}
