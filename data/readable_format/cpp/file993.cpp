#include <iostream>
#include <vector>

class TyColumn {
public:
    void compute_column(int nz, std::vector<std::vector<double>>& q, std::vector<std::vector<double>>& t, int nproma) {
        for (int i = 0; i < nz; ++i) {
            for (int j = 0; j < nproma; ++j) {
                q[i][j] *= 2.0;
                t[i][j] += 10.0;
            }
        }
    }
};

class MoColumnExtra {
public:
    void compute_one(int nz, std::vector<std::vector<double>>& q, std::vector<std::vector<double>>& t, int nproma) {
        TyColumn column;
        column.compute_column(nz, q, t, nproma);
    }
};

// Simple mechanism to compare two matrices.
bool matricesEqual(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].size() != b[i].size()) return false;
        for (size_t j = 0; j < a[i].size(); ++j) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main() {
    MoColumnExtra testObject;
    std::vector<std::vector<double>> t{{1.0, 2.0}};
    std::vector<std::vector<double>> q{{3.0, 4.0}};
    int nz = 1;
    int nproma = 2;

    // Expected results after computation.
    std::vector<std::vector<double>> expectedT{{11.0, 12.0}};
    std::vector<std::vector<double>> expectedQ{{6.0, 8.0}};

    // Compute
    testObject.compute_one(nz, q, t, nproma);

    // Test the results
    if (matricesEqual(t, expectedT) && matricesEqual(q, expectedQ)) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}