void init_array(int m, int n, double &float_n, double dat[][m]){
 float_n = 1.2;
 for (int i = 0; i < m; i++)
 for (int j = 0; j < n; j++)
 dat[j][i] = (double(i - 1) * double(j - 1)) / double(m);
}
