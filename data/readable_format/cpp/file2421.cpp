#include <iostream>
#include <array>

int main() {
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    std::array<double, 5> b = {1.0, 0.0, 1.0, 0.0, 1.0};

    for (size_t i = 0; i < a.size(); ++i) {
        if (b[i] != 0.0) {
            a[i] += 10;
        }
    }

    std::array<int, 5> expected_a = {11, 2, 13, 4, 15};
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != expected_a[i]) {
            std::cerr << "Error: a[" << i << "] = " << a[i] << " does not match expected value " << expected_a[i] << std::endl;
            return 1; // STOP 1 equivalent
        }
    }

    return 0;
}