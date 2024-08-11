// clusfgt.cpp
#include <iostream>
#include <vector>
#include <cassert>

void clusfgt(int n, const std::vector<float>& x, int incx, float target, std::vector<std::vector<int>>& index, int& nclus) {
    if (n < 1) {
        nclus = 0;
        return;
    }

    int ib = (incx >= 0) ? 0 : -(incx * (n - 1));
    nclus = 0;

    for (int i = 0; i < n; ++i) {
        if (x[ib] > target) {
            if (nclus == 0 || ib - incx < 0 || x[ib - incx] <= target) {
                if (nclus > 0) {
                    index[1][nclus - 1] = i;
                }
                nclus++;
                index[0][nclus - 1] = i + 1; // Adjusting for 1-based indexing
            }
            if (i == n - 1) {
                index[1][nclus - 1] = i + 1; // Adjusting for 1-based indexing
            }
        } else if (ib - incx >= 0 && x[ib - incx] > target) {
            index[1][nclus - 1] = i;
        }
        ib += incx;
    }
}

void test(const std::vector<float>& x, int incx, float target, const std::vector<std::vector<int>>& expected, int expectedNclus) {
    std::vector<std::vector<int>> index(2, std::vector<int>(x.size(), 0));
    int nclus = 0;
    clusfgt(x.size(), x, incx, target, index, nclus);

    assert(nclus == expectedNclus);
    for (int i = 0; i < 2; ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) {
            assert(index[i][j] == expected[i][j]);
        }
    }
    std::cout << "Test passed." << std::endl;
}

int main() {
    // Test 1
    std::vector<float> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    int incx = 1;
    float target = 3.5;
    std::vector<std::vector<int>> expected = {{4}, {5}};
    test(x, incx, target, expected, 1);

    // Add more tests as needed...

    return 0;
}