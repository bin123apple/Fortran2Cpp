#include <iostream>
#include <vector>

std::vector<std::vector<float>> matmul(const std::vector<std::vector<float>>& a, const std::vector<std::vector<float>>& b) {
    size_t a_rows = a.size(), a_cols = a[0].size(), b_cols = b[0].size();
    std::vector<std::vector<float>> ret(a_rows, std::vector<float>(b_cols, 0.0f));

    for (size_t i = 0; i < a_rows; ++i)
        for (size_t j = 0; j < b_cols; ++j)
            for (size_t k = 0; k < a_cols; ++k)
                ret[i][j] += a[i][k] * b[k][j];

    return ret;
}

int main() {
    std::vector<std::vector<float>> a(3, std::vector<float>(2, 1.0f));
    std::vector<std::vector<float>> b(2, std::vector<float>(3, 2.3f));

    auto ret = matmul(a, b);

    // Output the result for verification (not in actual tests)
    std::cout << "Matrix ret:" << std::endl;
    for (const auto& row : ret) {
        for (float val : row) std::cout << val << " ";
        std::cout << std::endl;
    }

    return 0;
}