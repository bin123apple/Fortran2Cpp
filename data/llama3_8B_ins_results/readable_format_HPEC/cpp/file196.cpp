#include <iostream>
#include <vector>

using namespace std;

void kernel_trisolv(int n, vector<vector<double>>& a, vector<double>& c, vector<double>& x) {
    for (int i = 1; i <= n; i++) {
        x[i-1] = c[i-1];
        for (int j = 1; j < i; j++) {
            x[i-1] -= a[j-1][i-1] * x[j-1];
        }
        x[i-1] /= a[i-1][i-1];
    }
}

int main() {
    int n = 10; // replace with your desired value
    vector<vector<double>> a(n, vector<double>(n));
    vector<double> c(n);
    vector<double> x(n);

    // initialize a, c, and x with your desired values

    kernel_trisolv(n, a, c, x);

    // print the result
    for (int i = 0; i < n; i++) {
        cout << x[i] << endl;
    }

    return 0;
}
