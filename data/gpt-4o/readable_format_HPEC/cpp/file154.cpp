#include <complex>
using namespace std;

void evolve(complex<double> u0[], complex<double> u1[], double twiddle[], int d1, int d2, int d3) 
{
  for (int k = 0; k < d3; k++)
    for (int j = 0; j < d2; j++)
      for (int i = 0; i < d1; i++)
      {
        u0[i + d1*(j + d2*k)] *= twiddle[i + d1*(j + d2*k)];
        u1[i + d1*(j + d2*k)] = u0[i + d1*(j + d2*k)];
      }
}
