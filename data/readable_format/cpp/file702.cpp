#include <vector>
#include <iostream>
#include <cassert>

// Define the clusigt function directly in this file
void clusigt(int n, const std::vector<int>& x, int incx, int target, std::vector<std::vector<int>>& index, int& nclus) {
    if (n < 1) {
        nclus = 0;
        return;
    }

    int ib, ie, nb, ne;
    if (incx >= 0) {
        ib = 0;
        ie = 0;
    } else {
        ib = 1 - incx * (n - 1) - 1;
        ie = 1 - incx * (n - 1) - 1;
    }

    nb = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[ib] > target) {
            if (i == 1 || x[ib - incx] <= target) {
                nb++;
                index[0][nb - 1] = i;
            }
        }
        ib += incx;
    }

    ne = 0;
    if (nb > 0) {
        for (int i = 1; i < n; ++i) {
            if (x[ie] > target && x[ie + incx] <= target) {
                index[1][ne] = i;
                ne++;
            }
            ie += incx;
        }
        if (x[ie] > target) {
            index[1][ne] = n;
            ne++;
        }
    }

    nclus = nb;
}

int main() {
    std::vector<int> x;
    std::vector<std::vector<int>> index(2, std::vector<int>(5, 0)); // Note: Adjust size as needed for your tests
    int nclus;

    // Test 1: Array with all elements below the target
    x = {1, 2, 3, 4, 5};
    clusigt(5, x, 1, 10, index, nclus);
    assert(nclus == 0);

    // Test 2: Array with all elements above the target
    x = {11, 12, 13, 14, 15};
    clusigt(5, x, 1, 10, index, nclus);
    assert(nclus == 1);

    // Add more tests as needed...

    std::cout << "All tests passed." << std::endl;
    return 0;
}