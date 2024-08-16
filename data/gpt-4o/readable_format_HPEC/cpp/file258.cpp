void print_array(int nx, int ny, DATA_TYPE ex[][nx], DATA_TYPE ey[][nx], DATA_TYPE hz[][nx]) {
 for (int i = 0; i < nx; i++) {
  for (int j = 0; j < ny; j++) {
   printf(DATA_PRINTF_MODIFIER, ex[j][i]);
   printf(DATA_PRINTF_MODIFIER, ey[j][i]);
   printf(DATA_PRINTF_MODIFIER, hz[j][i]);
   if (((i * nx) + j) % 20 == 0) {
    printf("
");
   }
  }
 }
 printf("
");
}
