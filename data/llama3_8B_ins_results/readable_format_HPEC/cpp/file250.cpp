#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, vector<double>& a, vector<double>& b) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[j][i] = (double(i - 1) * (j + 1) + 2.0) / n;
      b[j][i] = (double(i - 1) * (j + 2) + 3.0) / n;
    }
  }
}

int main() {
  int n = 10; // adjust this value as needed
  vector<vector<double>> a(n, vector<double>(n));
  vector<vector<double>> b(n, vector<double>(n));

  init_array(n, a, b);

  // print the arrays for verification
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[j][i] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << b[j][i] << " ";
    }
    cout << endl;
  }

  return 0;
}
