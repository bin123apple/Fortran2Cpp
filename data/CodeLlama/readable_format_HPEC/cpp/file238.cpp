#include <iostream>
#include <vector>

using namespace std;

void init_array(double& alpha, double& beta, vector<vector<double>>& a, vector<vector<double>>& b, vector<vector<double>>& c, vector<vector<double>>& d, int ni, int nj, int nk, int nl) {
    alpha = 32412;
    beta = 2123;

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<double>((i * j) / ni);
        }
    }

    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<double>((i * j) / nj);
        }
    }

    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<double>((i * (j + 2)) / nl);
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] = static_cast<double>((i * (j + 1)) / nk);
        }
    }
}

int main() {
    int ni = 5, nj = 5, nk = 5, nl = 5;
    double alpha, beta;
    vector<vector<double>> a(nk, vector<double>(ni)), b(nj, vector<double>(nk)), c(nl, vector<double>(nj)), d(nl, vector<double>(ni));

    init_array(alpha, beta, a, b, c, d, ni, nj, nk, nl);

    // Optional: Print the arrays to verify the initialization
    cout << "Alpha: " << alpha << ", Beta: " << beta << endl;
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            cout << "a[" << j << "][" << i << "] = " << a[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            cout << "b[" << j << "][" << i << "] = " << b[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < nj; ++j) {
            cout << "c[" << j << "][" << i << "] = " << c[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            cout << "d[" << j << "][" << i << "] = " << d[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
