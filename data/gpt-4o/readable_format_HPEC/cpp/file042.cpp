#include <stdio.h>

double* newSxx;
double* newSyy;
int len = 1000;

void foo(double* newSxx, double* newSyy, int len);

int main()
{
 newSxx = new double[len];
 newSyy = new double[len];

 foo(newSxx, newSyy, len);

 if(newSxx != nullptr)
 {
  delete[] newSxx;
  newSxx = nullptr;
 }

 if(newSyy != nullptr)
 {
  delete[] newSyy;
  newSyy = nullptr;
 }

 return 0;
}

void foo(double* newSxx, double* newSyy, int len)
{
 // function implementation
}
