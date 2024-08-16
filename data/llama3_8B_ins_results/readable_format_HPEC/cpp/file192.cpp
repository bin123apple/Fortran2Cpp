#include <iostream>
#include <cmath>

void initArray(int m, int n, double& float_n, double** dat) {
  float_n = 1.2;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      dat[j][i] = (double(i - 1) * double(j - 1)) / m;
    }
  }
}

int main() {
  int m = 10;
  int n = 10;
  double float_n;
  double** dat = new double*[n];
  for (int i = 0; i < n; i++) {
    dat[i] = new double[m];
  }

  initArray(m, n, float_n, dat);

  // Print the array
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << dat[j][i] << " ";
    }
    std::cout << std::endl;
  }

  // Don't forget to delete the dynamically allocated memory
  for (int i = 0; i < n; i++) {
    delete[] dat[i];
  }
  delete[] dat;

  return 0;
}
