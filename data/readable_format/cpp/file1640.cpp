#include <iostream>
#include <vector>
#include <cassert>

void reorderrhs(std::vector<double>& a, std::vector<double>& b, std::vector<double>& vold, std::vector<std::vector<int>>& neighblock, int nneighblock) {
    int indexf, iel, i;

    for (int j = 0; j < nneighblock; ++j) {
        indexf = neighblock[0][j]; // Adjusted for 0-based indexing in C++
        iel = neighblock[1][j];    // Adjusted for 0-based indexing in C++
        i = neighblock[2][j];      // Adjusted for 0-based indexing in C++
        b[i] = b[i] - a[indexf] * vold[iel];
    }
}

int main() {
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> b = {5.0, 4.0, 3.0, 2.0, 1.0};
    std::vector<double> vold = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<std::vector<int>> neighblock = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}};
    int nneighblock = 3;

    reorderrhs(a, b, vold, neighblock, nneighblock);

    std::cout << "Modified b:" << std::endl;
    for (const auto& value : b) {
        std::cout << value << std::endl;
    }

    return 0;
}