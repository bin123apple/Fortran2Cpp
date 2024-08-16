#include <iostream>
#include <vector>
#include <omp.h>

bool testMatrixUpdate() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] += 1;
        }
    }

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (a[i][j] != 100) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (testMatrixUpdate()) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }
    return 0;
}
