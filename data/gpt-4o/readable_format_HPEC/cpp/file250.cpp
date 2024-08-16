void init_array(int n, double a[][n], double b[][n])
{
 for (int i = 0; i < n; ++i)
 for (int j = 0; j < n; ++j)
 {
 a[j][i] = (static_cast<double>(i) * static_cast<double>(j + 1) + 2) / n;
 b[j][i] = (static_cast<double>(i) * static_cast<double>(j + 2) + 3) / n;
 }
}
