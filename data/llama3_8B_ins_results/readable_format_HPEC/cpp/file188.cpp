#include <iostream>
#include <vector>

using namespace std;

void kernel_durbin(int n, vector<vector<double>> y, vector<vector<double>> sumArray, vector<double> alpha, vector<double> beta, vector<double> r, vector<double> outArray) {
    // Initialize variables
    double beta1 = 1.0;
    double alpha1 = r[0];
    double y11 = r[0];

    // Loop through k from 2 to n
    for (int k = 2; k < n; k++) {
        beta[k] = beta[k-1] - (alpha[k-1] * alpha[k-1] * beta[k-1]);
        sumArray[k][0] = r[k];
        for (int i = 1; i < k; i++) {
            sumArray[k][i] = sumArray[k][i-1] + (r[k-i] * y[k-1][i]);
        }
        alpha[k] = alpha[k] - (sumArray[k][k] * beta[k]);
        for (int i = 1; i < k; i++) {
            y[k][i] = y[k-1][i] + (alpha[k] * y[k-1][k-i]);
        }
        y[k][k] = alpha[k];
    }

    // Copy the last row of y to outArray
    for (int i = 0; i < n; i++) {
        outArray[i] = y[n-1][i];
    }
}

int main() {
    int n = 10; // Replace with your desired value of n
    vector<vector<double>> y(n, vector<double>(n));
    vector<vector<double>> sumArray(n, vector<double>(n));
    vector<double> alpha(n);
    vector<double> beta(n);
    vector<double> r(n);
    vector<double> outArray(n);

    // Initialize y, r, alpha, beta, and outArray with your desired values

    kernel_durbin(n, y, sumArray, alpha, beta, r, outArray);

    // Print or use the output array as needed

    return 0;
}
