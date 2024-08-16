void print_array(int n, DATA_TYPE a[][n]) {
 int i, j;
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 printf(DATA_PRINTF_MODIFIER, a[j][i]);
 if (((i * n) + j) % 20 == 0) {
 printf("
");
 }
 }
 }
}
