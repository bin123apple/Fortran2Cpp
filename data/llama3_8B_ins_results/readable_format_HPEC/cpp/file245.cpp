#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, vector<double>& a, vector<double>& c, vector<double>& x) {
  for (int i = 0; i < n; i++) {
    c[i] = static_cast<double>(i - 1) / static_cast<double>(n);
    x[i] = static_cast<double>(i - 1) / static_cast<double>(n);
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      a[i][j] = static_cast<double>(i - 1) * static_cast<double>(j - 1) / static_cast<double>(n);
    }
  }
}

int main() {
  int n = 10; // adjust this value as needed
  vector<vector<double>> a(n, vector<double>(n));
  vector<double> c(n);
  vector<double> x(n);

  init_array(n, a, c, x);

  // print the initialized arrays
  for (int i = 0; i < n; i++) {
    cout << "c[" << i << "] = " << c[i] << endl;
    cout << "x[" << i << "] = " << x[i] << endl;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "a[" << i << "][" << j << "] = " << a[i][j] << endl;
    }
  }

  return 0;
}
