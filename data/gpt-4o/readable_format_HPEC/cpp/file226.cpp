void init_array(int n, double y[][n], double sumArray[][n], double alpha[], double beta[], double r[]) 
{
 for (int i = 0; i < n; ++i) 
 {
  alpha[i] = i;
  beta[i] = (double)(i+1) / (double)n / 2.0;
  r[i] = (double)(i+1) / (double)n / 4.0;
  for (int j = 0; j < n; ++j) 
  {
   y[j][i] = (double)(i+1)*(j+1) / (double)n;
   sumArray[j][i] = (double)(i+1)*(j+1) / (double)n;
  }
 }
}
