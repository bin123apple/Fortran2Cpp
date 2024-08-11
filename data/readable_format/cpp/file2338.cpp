#include <iostream>
#include <vector>
#include <cassert>

int ILASLC(int M, int N, const std::vector<std::vector<float>>& A) {
    const float ZERO = 0.0f;

    if (N == 0) {
        return N;
    } else {
        for (int col = N; col > 0; --col) {
            for (int row = 0; row < M; ++row) {
                if (A[row][col-1] != ZERO) {
                    return col;
                }
            }
        }
    }
    return 0;
}

void test_ILASLC() {
    std::vector<std::vector<float>> A = {
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 3.0f}
    };

    int M = 3;
    int N = 3;

    int result = ILASLC(M, N, A);
    std::cout << "Result: " << result << std::endl;

    assert(result == 3); // This is the expected result, indicating the last non-zero column index
}

int main() {
    test_ILASLC();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}