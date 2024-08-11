#include <iostream>
#include <vector>

void reorderRHS(const std::vector<double>& a, std::vector<double>& b, const std::vector<double>& vold, const std::vector<std::vector<int>>& neighBlock, int nNeighBlock) {
    for (int j = 0; j < nNeighBlock; ++j) {
        int indexF = neighBlock[0][j] - 1; // Adjusting for 0-based indexing
        int iel = neighBlock[1][j] - 1;    // Adjusting for 0-based indexing
        int i = neighBlock[2][j] - 1;      // Adjusting for 0-based indexing
        b[i] -= a[indexF] * vold[iel];
    }
}

int main() {
    std::vector<double> a = {1, 2, 3, 4, 5};
    std::vector<double> b = {0, 0, 0, 0, 0};
    std::vector<double> vold = {10, 20, 30, 40, 50};
    std::vector<std::vector<int>> neighBlock = {{1, 4, 2}, {3, 1, 3}, {5, 3, 5}};
    int nNeighBlock = 3;

    reorderRHS(a, b, vold, neighBlock, nNeighBlock);

    std::cout << "Resulting b array:" << std::endl;
    for (size_t i = 0; i < b.size(); ++i) {
        std::cout << "b(" << i + 1 << ") = " << b[i] << std::endl;
    }

    return 0;
}