#include <iostream>
#include <array>
#include <iomanip>

void r3mtm(const std::array<std::array<double, 3>, 3>& a, const std::array<std::array<double, 3>, 3>& b, std::array<std::array<double, 3>, 3>& c) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    std::array<std::array<double, 3>, 3> a{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    std::array<std::array<double, 3>, 3> b{{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}};
    std::array<std::array<double, 3>, 3> c;

    r3mtm(a, b, c);

    std::cout << "Resulting matrix C:" << std::endl;
    for (const auto &row : c) {
        for (const auto &elem : row) {
            std::cout << std::setw(8) << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}