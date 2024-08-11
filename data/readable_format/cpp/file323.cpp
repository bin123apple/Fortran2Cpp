#include <iostream>
#include <array>

void r3mtm(const std::array<std::array<double, 3>, 3>& a,
           const std::array<std::array<double, 3>, 3>& b,
           std::array<std::array<double, 3>, 3>& c) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = 0.0;
            for (int k = 0; k < 3; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    std::array<std::array<double, 3>, 3> a = {{
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    }};

    std::array<std::array<double, 3>, 3> b = {{
        {9.0, 8.0, 7.0},
        {6.0, 5.0, 4.0},
        {3.0, 2.0, 1.0}
    }};

    std::array<std::array<double, 3>, 3> c;

    r3mtm(a, b, c);

    std::cout << "Result matrix C:" << std::endl;
    for (const auto& row : c) {
        std::cout << '(';
        for (const auto& elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << ')' << std::endl;
    }

    return 0;
}