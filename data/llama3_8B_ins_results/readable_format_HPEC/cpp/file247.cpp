#include <iostream>
#include <vector>

using namespace std;

void init_array(int nr, int nq, int np, vector<vector<vector<double>>> &a, vector<vector<double>> &cFour) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nq; j++) {
            for (int k = 0; k < np; k++) {
                a[k][j][i] = ((double(i - 1) * double(j - 1)) + double(k - 1)) / np;
            }
        }
    }
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < np; j++) {
            cFour[j][i] = (double(i - 1) * double(j - 1)) / np;
        }
    }
}

int main() {
    int nr = 10;
    int nq = 10;
    int np = 10;
    vector<vector<vector<double>>> a(10, vector<vector<double>>(10, vector<double>(10)));
    vector<vector<double>> cFour(10, vector<double>(10));

    init_array(nr, nq, np, a, cFour);

    // Print the arrays
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nq; j++) {
            for (int k = 0; k < np; k++) {
                cout << a[k][j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < np; j++) {
            cout << cFour[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
