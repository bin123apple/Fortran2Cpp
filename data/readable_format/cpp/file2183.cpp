// File: ssmv_test.cpp
#include <iostream>
#include <vector>

void SSMV(int N, const std::vector<float>& X, std::vector<float>& Y, int NELT, 
          const std::vector<int>& IA, const std::vector<int>& JA, 
          const std::vector<float>& A, int ISYM) {
    Y.assign(N, 0.0f); // Initialize Y

    for (int ICOL = 0; ICOL < N; ++ICOL) {
        int IBGN = JA[ICOL] - 1; // Adjust for 0-based indexing
        int IEND = JA[ICOL + 1] - 2; // Adjust for 0-based indexing and inclusive upper bound
        for (int i = IBGN; i <= IEND; ++i) {
            Y[IA[i] - 1] += A[i] * X[ICOL]; // Adjust for 0-based indexing
        }
    }

    if (ISYM == 1) {
        for (int IROW = 0; IROW < N; ++IROW) {
            int JBGN = JA[IROW]; // Adjusted for 0-based indexing but skip self
            int JEND = JA[IROW + 1] - 2; // Adjust for inclusiveness
            for (int j = JBGN; j <= JEND; ++j) {
                Y[IROW] += A[j] * X[IA[j] - 1]; // Adjust for 0-based indexing
            }
        }
    }
}

int main() {
    const int N = 3;
    const int NELT = 6;
    std::vector<float> X = {1.0, 2.0, 3.0};
    std::vector<float> Y(N);
    std::vector<float> A = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<int> IA = {1, 2, 3, 1, 2, 3};
    std::vector<int> JA = {1, 3, 5, 7};
    int ISYM = 1;

    SSMV(N, X, Y, NELT, IA, JA, A, ISYM);

    std::cout << "Result Y: ";
    for (int i = 0; i < N; ++i) {
        std::cout << Y[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}