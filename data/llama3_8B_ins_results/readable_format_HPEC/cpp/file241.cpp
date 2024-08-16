#include <iostream>
#include <vector>

using namespace std;

void init_array(int n, vector<double>& a, vector<double>& x, vector<double>& y, vector<double>& b) {
    for (int i = 1; i <= n; i++) {
        x[i-1] = i;
        y[i-1] = (i/(double)n/2.0) + 1.0;
        b[i-1] = (i/(double)n/2.0) + 42.0;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            a[i-1][j-1] = (x[i-1] * y[j-1]) / n;
        }
    }
}

int main() {
    int n = 10; // adjust the value of n as needed
    vector<vector<double>> a(n+1, vector<double>(n+1));
    vector<double> x(n+1);
    vector<double> y(n+1);
    vector<double> b(n+1);

    init_array(n, a, x, y, b);

    // print the initialized arrays for verification
    for (int i = 0; i <= n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
        cout << "y[" << i << "] = " << y[i] << endl;
        cout << "b[" << i << "] = " << b[i] << endl;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << "a[" << i << "][" << j << "] = " << a[i][j] << endl;
        }
    }

    return 0;
}
