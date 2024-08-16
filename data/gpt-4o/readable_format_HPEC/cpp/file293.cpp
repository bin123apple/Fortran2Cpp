void init_array(int tmax, int nx, int ny, double** ex, double** ey, double** hz, double* fict)
{
 for (int i = 0; i < tmax; i++)
 fict[i] = double(i);

 for (int i = 0; i < nx; i++)
 for (int j = 0; j < ny; j++)
 {
 ex[j][i] = double(i * j) / nx;
 ey[j][i] = double(i * (j + 1)) / ny;
 hz[j][i] = double(i * (j + 2)) / nx;
 }
}
