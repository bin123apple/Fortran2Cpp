#include <iostream>
#include <vector>

using namespace std;

void initArray(int m, int n, double float_n, vector<vector<double>>& dat) {
  float_n = 1.2;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      dat[j][i] = (double)((i - 1) * (j - 1)) / m;
    }
  }
}

int main() {
  int m = 10;
  int n = 10;
  double float_n;
  vector<vector<double>> dat(n, vector<double>(m));

  initArray(m, n, float_n, dat);

  // Print the array
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << dat[j][i] << " ";
    }
    cout << endl;
  }

  return 0;
}
