#include <iostream>
#include <vector>

using namespace std;

void init_array(int ni, int nj, int nk, int nl, int nm, vector<vector<double>>& a, vector<vector<double>>& b, vector<vector<double>>& c, vector<vector<double>>& d) {
    a.resize(nk, vector<double>(ni));
    b.resize(nj, vector<double>(nk));
    c.resize(nm, vector<double>(nj));
    d.resize(nl, vector<double>(nm));

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nk; j++) {
            a[j][i] = (i - 1) * (j - 1) / ni;
        }
    }

    for (int i = 0; i < nk; i++) {
        for (int j = 0; j < nj; j++) {
            b[j][i] = (i - 1) * (j) / nj;
        }
    }

    for (int i = 0; i < nj; i++) {
        for (int j = 0; j < nm; j++) {
            c[i][j] = (i - 1) * (j + 2) / nl;
        }
    }

    for (int i = 0; i < nm; i++) {
        for (int j = 0; j < nl; j++) {
            d[i][j] = (i - 1) * (j + 1) / nk;
        }
    }
}

int main() {
    int ni = 10, nj = 20, nk = 30, nl = 40, nm = 50;
    vector<vector<double>> a, b, c, d;

    init_array(ni, nj, nk, nl, nm, a, b, c, d);

    // Print the initialized arrays
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

    for (int i = 0; i < nj; i++) {
        for (int j = 0; j < nm; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nm; i++) {
        for (int j = 0; j < nl; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
