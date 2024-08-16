#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

double foo(vector<double>& a, vector<double>& b, int len) {
    // implement the logic for foo function
    // for demonstration purposes, just return the sum of elements in b
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += b[i];
    }
    return sum;
}

int main() {
    int len = 1000;
    vector<double> a(len);
    vector<double> b(len);

    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        a[i] = (double(i) + 0.5) / 2.0;
        b[i] = 0.0;
    }

    double x = foo(a, b, len);
    cout << "b(50) = " << b[50] << endl;

    return 0;
}
