#include <iostream>
#define N 100
#define M 100
void print_array(int m, int symmat[N][M]) 
{
 for (int i = 0; i < m; i++) 
 {
  for (int j = 0; j < m; j++) 
  {
   std::cout << symmat[j][i] << " ";
   if ((i * m + j) % 20 == 0)
    std::cout << std::endl;
  }
 }
 std::cout << std::endl;
}
