#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, vector<double>& a, vector<double>& b) {
  for (int i = 0; i < n; i++) {
    a[i] = (double(i-1) + 2.0) / n;
    b[i] = (double(i-1) + 3.0) / n;
  }
}

int main() {
  int n = 10; // adjust this value as needed
  vector<double> a(n);
  vector<double> b(n);

  init_array(n, a, b);

  // print the arrays for verification
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "] = " << a[i] << endl;
    cout << "b[" << i << "] = " << b[i] << endl;
  }

  return 0;
}
