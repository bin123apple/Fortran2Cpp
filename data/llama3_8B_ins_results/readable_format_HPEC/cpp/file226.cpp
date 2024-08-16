#include <iostream>
#include <vector>

using namespace std;

void initArray(int n, vector<double>& y, vector<vector<double>>& sumArray, vector<double>& alpha, vector<double>& beta, vector<double>& r) {
    for (int i = 0; i < n; i++) {
        alpha[i] = i + 1;
        beta[i] = (i + 1.0) / (n * 2.0);
        r[i] = (i + 1.0) / (n * 4.0);
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            y[j][i] = (i + 1.0) * (j + 1.0) / n;
            sumArray[j][i] = (i + 1.0) * (j + 1.0) / n;
        }
    }
}

int main() {
    int n = 10; // adjust this value as needed
    vector<double> alpha(n);
    vector<double> beta(n);
    vector<double> r(n);
    vector<vector<double>> y(n, vector<double>(n));
    vector<vector<double>> sumArray(n, vector<double>(n));

    initArray(n, y, sumArray, alpha, beta, r);

    // print the arrays for verification
    for (int i = 0; i < n; i++) {
        cout << "alpha[" << i << "] = " << alpha[i] << endl;
        cout << "beta[" << i << "] = " << beta[i] << endl;
        cout << "r[" << i << "] = " << r[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "y[" << j << "][" << i << "] = " << y[j][i] << endl;
            cout << "sumArray[" << j << "][" << i << "] = " << sumArray[j][i] << endl;
        }
    }

    return 0;
}
