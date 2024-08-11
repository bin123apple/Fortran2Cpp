// File: F_and_Test.cpp
#include <iostream>

void F(double* x, double* v) {
  // Increment the first element of x by 1
  x[0] = x[0] + 1;
}

int main() {
  double X[1] = {5.0}; // Initialize with a value
  double V[1] = {10.0}; // Initialize with a value

  F(X, V);

  std::cout << "Test increment X[0]: " << X[0] << std::endl;
  std::cout << "V[0] should remain unchanged: " << V[0] << std::endl;

  return 0;
}