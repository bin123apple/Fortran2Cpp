#include <iostream>
#include <vector>

using namespace std;

void init_array(double& alpha, double& beta, vector<vector<double>>& a, vector<vector<double>>& b, vector<vector<double>>& c, vector<vector<double>>& d, int ni, int nj, int nk, int nl) {
    alpha = 32412.0;
    beta = 2123.0;

    a.resize(nk, vector<double>(ni));
    b.resize(nj, vector<double>(nk));
    c.resize(nl, vector<double>(nj));
    d.resize(nl, vector<double>(ni));

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nk; j++) {
            a[j][i] = (double)((i - 1) * (j - 1)) / ni;
        }
    }

    for (int i = 0; i < nk; i++) {
        for (int j = 0; j < nj; j++) {
            b[j][i] = (double)((i - 1) * (j)) / nj;
        }
    }

    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nj; j++) {
            c[j][i] = (double)((i - 1) * (j + 2)) / nl;
        }
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nl; j++) {
            d[j][i] = (double)((i - 1) * (j + 1)) / nk;
        }
    }
}

int main() {
    int ni = 10, nj = 20, nk = 30, nl = 40;
    double alpha, beta;
    vector<vector<double>> a, b, c, d;

    init_array(alpha, beta, a, b, c, d, ni, nj, nk, nl);

    // Print the arrays
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nk; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nk; i++) {
        for (int j = 0; j < nj; j++) {
            cout << b[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nj; j++) {
            cout << c[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nl; j++) {
            cout << d[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
