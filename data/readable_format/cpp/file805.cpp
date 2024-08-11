#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void dlasdt(int n, int &lvl, int &nd, int *inode, int *ndiml, int *ndimr, int msub) {
    const double TWO = 2.0;
    int i, il, ir, llst, maxn, ncrnt, nlvl;
    double temp;

    maxn = std::max(1, n);
    temp = std::log(static_cast<double>(maxn) / static_cast<double>(msub + 1)) / std::log(TWO);
    lvl = static_cast<int>(temp) + 1;

    i = n / 2;
    inode[0] = i + 1; // Adjusted for 0-based indexing
    ndiml[0] = i;     // Adjusted for 0-based indexing
    ndimr[0] = n - i - 1; // Adjusted for 0-based indexing
    il = -1; // Adjusted for 0-based indexing in the first iteration
    ir = 0;  // Adjusted for 0-based indexing in the first iteration
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
    const int N = 7;
    const int MSUB = 3;
    int lvl, nd;
    std::vector<int> inode(N), ndiml(N), ndimr(N);

    dlasdt(N, lvl, nd, inode.data(), ndiml.data(), ndimr.data(), MSUB);

    std::cout << "LVL: " << lvl << std::endl;
    std::cout << "ND: " << nd << std::endl;
    std::cout << "INODE: ";
    for (int i = 0; i < nd; ++i) {
        std::cout << inode[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "NDIML: ";
    for (int i = 0; i < nd; ++i) {
        std::cout << ndiml[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "NDIMR: ";
    for (int i = 0; i < nd; ++i) {
        std::cout << ndimr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}