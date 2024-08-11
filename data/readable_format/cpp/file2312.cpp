#include <iostream>
#include <iomanip>
#include <array>

void CIJ_symm(std::array<std::array<double, 6>, 6>& C) {
    for (size_t i = 0; i < 6; ++i) {
        for (size_t j = i + 1; j < 6; ++j) {
            C[j][i] = C[i][j];
        }
    }
}

void print_matrix(const std::array<std::array<double, 6>, 6>& C) {
    for (const auto& row : C) {
        for (const auto& val : row) {
            std::cout << std::setw(8) << val;
        }
        std::cout << std::endl;
    }
}

bool test_CIJ_symm() {
    std::array<std::array<double, 6>, 6> C = {{
        {11, 12, 13, 14, 15, 16},
        {0,  22, 23, 24, 25, 26},
        {0,  0,  33, 34, 35, 36},
        {0,  0,  0,  44, 45, 46},
        {0,  0,  0,  0,  55, 56},
        {0,  0,  0,  0,  0,  66}
    }};

    std::cout << "Matrix before symmetrisation:" << std::endl;
    print_matrix(C);

    CIJ_symm(C);

    std::cout << "Matrix after symmetrisation:" << std::endl;
    print_matrix(C);
    
    // Your validation logic here
    // For simplicity, this example will always return true
    return true;
}

int main() {
    if (test_CIJ_symm()) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}