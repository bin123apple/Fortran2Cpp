#include <vector>

void init_array(int n, double& alpha, double& beta, std::vector<std::vector<double>>& a, std::vector<std::vector<double>>& b, std::vector<double>& x)
{
 alpha = 43532.0;
 beta = 12313.0;

 for (int i = 0; i < n; i++)
 {
  x[i] = static_cast<double>(i) / static_cast<double>(n);
  for (int j = 0; j < n; j++)
  {
   a[j][i] = static_cast<double>(i * j) / static_cast<double>(n);
   b[j][i] = static_cast<double>(i * j) / static_cast<double>(n);
  }
 }
}
