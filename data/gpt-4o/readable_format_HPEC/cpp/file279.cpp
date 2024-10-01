#include <stdio.h>
#include <vector>
#include <omp.h>

int main()
{
 int n = 100;
 int m = 100;
 std::vector<std::vector<float>> b(n, std::vector<float>(m, 0));

 #pragma omp parallel for private(n)
 for (int j=1; j<n; j++)
 for (int i=0; i<m; i++)
 b[i][j] = b[i][j-1];

 printf ("b[50][50]=%f\n", b[50][50]);
 return 0;
}
