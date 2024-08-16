void print_array(int n, DATA_TYPE x[])
{
 for (int i = 0; i < n; i++)
 {
 printf(DATA_PRINTF_MODIFIER, x[i]);
 if (i % 20 == 0)
 printf("
");
 }
}
