#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Assuming OPS and ITCNT are defined here as global variables.
double OPS, ITCNT;

void dlasdt(int n, int& lvl, int& nd, int* inode, int* ndiml, int* ndimr, int msub) {
    const double TWO = 2.0;
    int i, il, ir, llst, maxn, ncrnt, nlvl;
    double temp;

    OPS += 2.0;
    maxn = std::max(1, n);
    temp = std::log(static_cast<double>(maxn) / static_cast<double>(msub + 1)) / std::log(TWO);
    lvl = static_cast<int>(temp) + 1;

    i = n / 2;
    inode[0] = i + 1; // Adjusted for 0-based indexing
    ndiml[0] = i;
    ndimr[0] = n - i - 1;
    il = -1; // Adjusted for 0-based indexing in the loop
    ir = 0;  // Adjusted for 0-based indexing in the loop
    llst = 1;

    for (nlvl = 1; nlvl <= lvl - 1; ++nlvl) {
        for (i = 0; i < llst; ++i) {
            il += 2;
            ir += 2;
            ncrnt = llst + i - 1; // Adjusted for 0-based indexing
            ndiml[il] = ndiml[ncrnt] / 2;
            ndimr[il] = ndiml[ncrnt] - ndiml[il] - 1;
            inode[il] = inode[ncrnt] - ndimr[il] - 1;
            ndiml[ir] = ndimr[ncrnt] / 2;
            ndimr[ir] = ndimr[ncrnt] - ndiml[ir] - 1;
            inode[ir] = inode[ncrnt] + ndiml[ir] + 1;
        }
        llst *= 2;
    }
    nd = llst * 2 - 1;
}

int main() {
    const int N = 8;
    int lvl, nd, msub = 2;
    int inode[N], ndiml[N], ndimr[N];

    // Initialize arrays to zero for clarity in output.
    for (int i = 0; i < N; ++i) {
        inode[i] = 0;
        ndiml[i] = 0;
        ndimr[i] = 0;
    }

    dlasdt(N, lvl, nd, inode, ndiml, ndimr, msub);

    cout << "LVL: " << lvl << endl;
    cout << "ND: " << nd << endl;
    cout << "INODE: ";
    for (int i = 0; i < N; ++i) cout << inode[i] << " ";
    cout << endl;
    cout << "NDIML: ";
    for (int i = 0; i < N; ++i) cout << ndiml[i] << " ";
    cout << endl;
    cout << "NDIMR: ";
    for (int i = 0; i < N; ++i) cout << ndimr[i] << " ";
    cout << endl;

    return 0;
}