#include <iostream>
#include <vector>
using namespace std;

void hrk_ud(const vector<vector<int>>& ielfa, const vector<vector<double>>& vel, const vector<int>& ipnei, int nef, const vector<double>& flux, vector<vector<double>>& vfa, int nfacea, int nfaceb) {
    int i, j, indexf, iel1, iel2;

    for (i = nfacea; i <= nfaceb; ++i) {
        iel2 = ielfa[1][i] - 1;  // Adjust for 0-based indexing in C++
        if (iel2 < 0) continue;
        iel1 = ielfa[0][i] - 1;  // Adjust for 0-based indexing
        j = ielfa[3][i];
        indexf = ipnei[iel1] + j - 1;  // Adjust for 0-based indexing and match Fortran logic

        if (flux[indexf] >= 0.0) {
            vfa[6][i] = vel[iel1][6];
        } else {
            vfa[6][i] = vel[iel2][6];
        }
    }
}

int main() {
    const int nef = 5;
    const int nfaces = 4;

    vector<vector<int>> ielfa = { {1, 1, 2, 3}, {2, 2, 4, 4}, {0, 1, 2, 3}, {3, 3, 3, 2} };
    vector<int> ipnei = { 1, 1, 2, 3, 4 };  // Adjusted to match Fortran logic
    vector<vector<double>> vel(nef, vector<double>(8));
    vector<double> flux = { 0.5, -0.2, 0.0, 0.8, -0.1, 0.3, -0.4, 0.6, -0.5, 0.2 };
    vector<vector<double>> vfa(8, vector<double>(nfaces, 0.0));

    // Initialize vel
    for (int i = 0; i < nef; ++i) {
        for (int j = 0; j < 8; ++j) {
            vel[i][j] = static_cast<double>(i + 1);
        }
    }

    // Call the function
    hrk_ud(ielfa, vel, ipnei, nef, flux, vfa, 0, nfaces - 1);

    // Print the results
    cout << "vfa[6]: ";
    for (int i = 0; i < nfaces; ++i) {
        cout << vfa[6][i] << " ";
    }
    cout << endl;

    return 0;
}