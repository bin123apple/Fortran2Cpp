#include <cmath>
const double M_PI = 3.14159265358979323846;
void init_array(int nx, int ny, double a[][nx], double r[], double p[])
{
 int i, j;
 for (i = 0; i < ny; i++)
 p[i] = double(i) * M_PI;
 for (i = 0; i < nx; i++)
 {
 r[i] = double(i) * M_PI;
 for (j = 0; j < ny; j++)
 a[j][i] = (double(i) * double(j)) / nx;
 }
}
