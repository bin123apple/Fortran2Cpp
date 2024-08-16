#include <iostream>
#include <vector>

using namespace std;

void init_array(int ni, int nj, double alpha, double beta, vector<vector<double>>& a, vector<vector<double>>& c) {
    alpha = 32412.0;
    beta = 2123.0;

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            a[j][i] = (double(i - 1) * double(j - 1)) / ni;
        }
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            c[j][i] = ((double(i - 1) * double(j - 1))) / ni;
        }
    }
}

int main() {
    int ni = 10; // adjust this value as needed
    int nj = 10; // adjust this value as needed
    double alpha, beta;
    vector<vector<double>> a(ni, vector<double>(ni));
    vector<vector<double>> c(ni, vector<double>(nj));

    init_array(ni, nj, alpha, beta, a, c);

    // print the arrays for verification
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            cout << c[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
