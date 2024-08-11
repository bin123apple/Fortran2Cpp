#include <iostream>
#include <vector>

void make_phbm(std::vector<std::vector<float>>& beam, int m, int n, int ibc, int jbc, float alpha, int status) {
    if (status != 0) return;
    ibc -= 1; // Adjust for 0-based indexing
    jbc -= 1;
    beam[ibc][jbc] = beam[ibc][jbc] + alpha * beam[ibc][jbc];
}

int main() {
    int m = 3, n = 3, ibc = 2, jbc = 3, status;
    float alpha = 0.5;
    std::vector<std::vector<float>> beam = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Test 1: Verify no modification when status is not 0
    status = 1;
    make_phbm(beam, m, n, ibc, jbc, alpha, status);
    if (beam[1][2] == 6) {
        std::cout << "C++ Test 1 Passed" << std::endl;
    } else {
        std::cout << "C++ Test 1 Failed" << std::endl;
    }

    // Reset beam for the next test
    beam = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Test 2: Confirm correct modification when status is 0
    status = 0;
    make_phbm(beam, m, n, ibc, jbc, alpha, status);
    if (beam[1][2] == 9) {
        std::cout << "C++ Test 2 Passed" << std::endl;
    } else {
        std::cout << "C++ Test 2 Failed" << std::endl;
    }

    return 0;
}