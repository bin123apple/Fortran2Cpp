#include <cmath>
#define DATA_TYPE double
void init_array(DATA_TYPE a[100][100], DATA_TYPE x[100], int nx, int ny)
{
 int i, j;
 for (i = 0; i < ny; i++)
 {
 x[i] = double(i) * M_PI;
 for (j = 0; j < ny; j++)
 a[j][i] = (double(i * j)) / nx;
 }
}
