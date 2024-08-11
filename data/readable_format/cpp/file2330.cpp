#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

int ILACLR(int M, int N, const std::vector<std::vector<std::complex<float>>>& A) {
    std::complex<float> ZERO(0.0f, 0.0f);

    if (M == 0) {
        return M;
    } else if (A[M-1][0] != ZERO || A[M-1][N-1] != ZERO) {
        return M;
    } else {
        int ILACLR = 0;
        for (int J = 0; J < N; ++J) {
            int I = M;
            while (I >= 1 && A[I-1][J] == ZERO) {
                --I;
            }
            ILACLR = std::max(ILACLR, I);
        }
        return ILACLR;
    }
}

void run_tests() {
    std::vector<std::vector<std::complex<float>>> A;

    // Test case 1
    A = std::vector<std::vector<std::complex<float>>>(3, std::vector<std::complex<float>>(3, std::complex<float>(0.0f, 0.0f)));
    std::cout << "Test case 1 result: " << ILACLR(3, 3, A) << std::endl;

    // Test case 2
    A[2][0] = std::complex<float>(1.0f, 0.0f);
    std::cout << "Test case 2 result: " << ILACLR(3, 3, A) << std::endl;

    // Test case 3
    A[2][0] = std::complex<float>(0.0f, 0.0f);
    A[2][2] = std::complex<float>(1.0f, 0.0f);
    std::cout << "Test case 3 result: " << ILACLR(3, 3, A) << std::endl;

    // Test case 4
    A = std::vector<std::vector<std::complex<float>>>(3, std::vector<std::complex<float>>(3, std::complex<float>(0.0f, 0.0f)));
    A[1][1] = std::complex<float>(1.0f, 0.0f);
    std::cout << "Test case 4 result: " << ILACLR(3, 3, A) << std::endl;
}

int main() {
    run_tests();
    return 0;
}