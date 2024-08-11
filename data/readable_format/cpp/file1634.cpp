#include <iostream>
#include <vector>

using namespace std;

void floop24_F77(int N, vector<float>& x, const vector<float>& a, const vector<float>& b, const vector<float>& c, const vector<float>& d, vector<float>& y) {
    for (int i = 0; i < N; ++i) {
        x[i] = a[i] * c[i] - b[i] * c[i];
        y[i] = a[i] * d[i] + b[i] + c[i];
    }
}

int main() {
    int N = 5;
    vector<float> x(N), a(N, 1.0f), b(N, 2.0f), c(N, 3.0f), d(N, 4.0f), y(N);

    floop24_F77(N, x, a, b, c, d, y);

    cout << "Results from C++ test:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i] << endl;
    }

    return 0;
}