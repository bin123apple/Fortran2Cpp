#include <iostream>
#include <vector>

using namespace std;

void kernel_trmm(int ni, double alpha, vector<vector<double>>& a, vector<vector<double>>& b) {
    for (int i = 2; i < ni; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k < i; k++) {
                b[j][i] += alpha * a[k][i] * b[k][j];
            }
        }
    }
}

int main() {
    int ni = 10; // replace with your desired value
    double alpha = 2.0; // replace with your desired value
    vector<vector<double>> a(ni, vector<double>(ni));
    vector<vector<double>> b(ni, vector<double>(ni));

    // initialize a and b with your desired values

    kernel_trmm(ni, alpha, a, b);

    // print the result
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < ni; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
