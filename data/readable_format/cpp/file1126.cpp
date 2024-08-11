#include <iostream>
#include <vector>
#include <complex>
#include <cmath> // For std::abs

template<typename T>
class SymCnstODiag {
public:
    static std::vector<std::vector<T>> sym_cnst_odiag_real_dp(const std::vector<std::vector<T>>& matrix) {
        std::vector<std::vector<T>> result = matrix;
        for (auto& row : result) {
            for (auto& elem : row) {
                elem += 1.0;
            }
        }
        return result;
    }
};

void assert_equal(double a, double b, const std::string& message) {
    if(std::abs(a - b) > 1e-6) {
        std::cerr << "Assertion failed: " << message << ", " << a << " != " << b << std::endl;
    } else {
        std::cout << "Test passed: " << message << std::endl;
    }
}

void run_tests() {
    std::vector<std::vector<double>> matrix = {{2.0, 3.0}, {3.0, 4.0}};
    auto result = SymCnstODiag<double>::sym_cnst_odiag_real_dp(matrix);

    assert_equal(result[0][0], 3.0, "sym_cnst_odiag_real_dp(matrix)[0][0]");
    // Add more assertions as needed
}

int main() {
    run_tests();
    return 0;
}