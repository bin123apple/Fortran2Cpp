#include <iostream>
#include <vector>
using namespace std;

void jgroup(int n, const vector<int>& ia, const vector<int>& ja, int maxg, int& ngrp, vector<int>& igp, vector<int>& jgp, vector<int>& incl, vector<int>& jdone, int& ier) {
    ier = 0;
    for (int j = 0; j < n; ++j) {
        jdone[j] = 0;
    }
    int ncol = 1;
    int ng;
    for (ng = 0; ng < maxg; ++ng) {
        igp[ng] = ncol;
        for (int i = 0; i < n; ++i) {
            incl[i] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (jdone[j] == 1) continue;
            int kmin = ia[j] - 1; // Adjusting for 0-based indexing
            int kmax = ia[j + 1] - 2; // Adjusting for 0-based indexing and the loop condition
            for (int k = kmin; k <= kmax; ++k) {
                int i = ja[k] - 1; // Adjusting for 0-based indexing
                if (incl[i] == 1) goto next_j;
            }
            jgp[ncol - 1] = j + 1; // Adjusting for 0-based indexing in C++
            ncol++;
            jdone[j] = 1;
            for (int k = kmin; k <= kmax; ++k) {
                int i = ja[k] - 1; // Adjusting for 0-based indexing
                incl[i] = 1;
            }
        next_j:;
        }
        if (ncol == igp[ng]) break;
    }
    if (ncol <= n) {
        ier = 1;
        return;
    }
    ngrp = ng; // Update ngrp based on the last value of ng
}

// Main function for testing
int main() {
    int n = 5, maxg = 5;
    vector<int> ia = {1, 3, 5, 7, 9, 11}; // Adjusted for 1-based indexing
    vector<int> ja = {1, 2, 1, 3, 2, 4, 3, 5, 4, 5}; // Adjusted for 1-based indexing
    vector<int> igp(maxg, 0), jgp(n, 0), incl(n, 0), jdone(n, 0);
    int ngrp = 0, ier = 0;

    // Call the jgroup function
    jgroup(n, ia, ja, maxg, ngrp, igp, jgp, incl, jdone, ier);

    // Output results for verification
    cout << "ier = " << ier << endl;
    cout << "ngrp = " << ngrp << endl;
    cout << "igp = ";
    for (int val : igp) cout << val << " ";
    cout << endl << "jgp = ";
    for (int val : jgp) cout << val << " ";
    cout << endl;

    return 0;
}