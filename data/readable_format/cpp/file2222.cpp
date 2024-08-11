#include <array>
#include <cmath>

void fi_a3(const std::array<double, 3>& r, std::array<double, 3>& p) {
    p[0] = r[0] + r[1] + r[2];
    p[1] = std::pow(r[0], 2) + std::pow(r[1], 2) + std::pow(r[2], 2);
    p[2] = std::pow(r[0], 3) + std::pow(r[1], 3) + std::pow(r[2], 3);
}

int main() {
    // Example usage
    std::array<double, 3> r = {1.0, 2.0, 3.0};
    std::array<double, 3> p;

    fi_a3(r, p);

    // Output results
    for (const auto& val : p) {
        std::cout << val << std::endl;
    }

    return 0;
}