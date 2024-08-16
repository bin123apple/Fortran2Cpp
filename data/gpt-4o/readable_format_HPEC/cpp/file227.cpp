```cpp
template <typename DATA_TYPE>
void kernel_gemm(int ni, int nj, int nk, DATA_TYPE alpha, DATA_TYPE beta, DATA_TYPE** c, DATA_TYPE** a, DATA_TYPE** b) 
{
  for (int i = 0; i < ni; i++) 
  {
    for (int j = 0; j < nj; j++) 
    {
      c[j][i] *= beta;
      for (int k = 0; k < nk; k++) 
      {
        c[j][i] += alpha * a[k][i] * b[j][k];
      }
    }
  }
}
```
