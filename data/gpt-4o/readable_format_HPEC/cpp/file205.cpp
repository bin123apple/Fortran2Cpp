#include <iostream>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d "
void print_array(int ni, int nj, DATA_TYPE c[100][100])
{
 for (int i = 0; i < ni; i++)
 {
 for (int j = 0; j < nj; j++)
 {
 printf(DATA_PRINTF_MODIFIER, c[j][i]);
 if (((i * ni) + j) % 20 == 0) printf("
");
 }
 }
 printf("
");
}
