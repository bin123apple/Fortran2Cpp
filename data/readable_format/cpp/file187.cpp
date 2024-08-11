#include <iostream>
#include <vector>

void clusige(int n, const std::vector<int>& x, int incx, int target, std::vector<std::vector<int>>& index, int& nclus) {
    int ib, ie, nb = 0;
    if (n < 1) return;

    ib = 0; // Adjust for 0-based indexing in C++
    for (int i = 0; i < n; ++i) {
        if (x[ib] >= target) {
            if (nb == 0 || (x[ib - incx] < target)) {
                index[0][nb] = i + 1; // Adjust for 1-based indexing output
                ++nb;
            }
            ie = i + 1; // Adjust for 1-based indexing output
        }
        ib += incx;
    }
    
    if (nb > 0) {
        index[1][nb - 1] = ie; // Only saving the last end index
    }
    nclus = nb;
}

int main() {
    std::vector<int> x = {3, 6, 9, 15, 20, 25, 30, 35, 40, 2};
    int target = 10, incx = 1, nclus = 0;
    std::vector<std::vector<int>> index(2, std::vector<int>(x.size(), 0));

    clusige(x.size(), x, incx, target, index, nclus);

    std::cout << "Number of clusters: " << nclus << std::endl;
    if (nclus > 0) {
        std::cout << "Start indices: ";
        for (int i = 0; i < nclus; ++i) std::cout << index[0][i] << " ";
        std::cout << std::endl << "End indices: ";
        for (int i = 0; i < nclus; ++i) std::cout << index[1][i] << " ";
        std::cout << std::endl;
    }

    return 0;
}