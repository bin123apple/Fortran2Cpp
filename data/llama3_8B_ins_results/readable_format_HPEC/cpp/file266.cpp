#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, vector<double>& a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[j][i] = (double(i) * double(j)) / n;
    }
  }
}

int main() {
  int n = 10; // adjust this value as needed
  vector<vector<double>> a(n, vector<double>(n));
  init_array(n, a);

  // print the array for verification
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[j][i] << " ";
    }
    cout << endl;
  }

  return 0;
}
