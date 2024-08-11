#include <iostream>
#include <vector>

void descramble_matrix(std::vector<std::vector<double>>& mat, int na, const std::vector<int>& nfps, const std::vector<int>& ixshells, int nshells) {
    if (na <= 0) {
        return;
    }

    std::vector<int> nfps_orig(nshells+1, 0); // Adjusted for 1-based indexing
    std::vector<double> xa(na);
    std::vector<int> ixa(na + 1); // Adjusted for 1-based indexing

    for (int i = 1; i <= nshells; ++i) {
        nfps_orig[ixshells[i-1]] = nfps[i-1];
    }

    int istart = 1;
    for (int i = 1; i <= nshells; ++i) {
        int ishell = ixshells[i-1];

        int n = 0;
        for (int j = 1; j < ishell; ++j) {
            n += nfps_orig[j];
        }

        for (int j = 1; j <= nfps_orig[ishell]; ++j) {
            ixa[istart] = n + j;
            ++istart;
        }
    }

    for (int j = 1; j <= na; ++j) {
        for (int i = 1; i <= na; ++i) {
            xa[i-1] = mat[i-1][j-1];
        }

        for (int i = 1; i <= na; ++i) {
            mat[ixa[i]-1][j-1] = xa[i-1];
        }
    }

    for (int i = 1; i <= na; ++i) {
        for (int j = 1; j <= na; ++j) {
            xa[j-1] = mat[i-1][j-1];
        }

        for (int j = 1; j <= na; ++j) {
            mat[i-1][ixa[j]-1] = xa[j-1];
        }
    }
}

int main() {
    int na = 4;
    int nshells = 2;
    std::vector<int> nfps = {2, 2};
    std::vector<int> ixshells = {1, 2};

    std::vector<std::vector<double>> mat = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0, 16.0}
    };

    descramble_matrix(mat, na, nfps, ixshells, nshells);

    std::cout << "Matrix after descrambling:" << std::endl;
    for (const auto& row : mat) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}