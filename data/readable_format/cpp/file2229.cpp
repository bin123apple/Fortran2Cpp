#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// Define the structure equivalent to the Fortran type
struct t {
    int ii = 55;
};

// Function f1 equivalent
std::shared_ptr<t> f1() {
    auto f1 = std::make_shared<t>();
    f1->ii = 123;
    return f1;
}

// Function f2 equivalent
std::vector<std::shared_ptr<t>> f2() {
    std::vector<std::shared_ptr<t>> f2(3);
    for (int i = 0; i < 3; ++i) {
        f2[i] = std::make_shared<t>();
        f2[i]->ii = -11 * (i + 1);
    }
    return f2;
}

int main() {
    // Pointer p1 equivalent
    auto p1 = f1();
    if (p1->ii != 123) {
        std::cerr << "STOP 1" << std::endl;
        return 1;
    }

    // Pointer p2 equivalent
    auto p2 = f2();
    std::vector<int> expected_values = {-11, -22, -33};
    for (int i = 0; i < 3; ++i) {
        if (p2[i]->ii != expected_values[i]) {
            std::cerr << "STOP 2" << std::endl;
            return 2;
        }
    }

    // Pointer p3 equivalent, assuming 2D vector of shared pointers
    std::vector<std::vector<std::shared_ptr<t>>> p3(3, std::vector<std::shared_ptr<t>>(3));
    auto f2_result = f2();
    for (int j = 0; j < 3; ++j) {
        p3[1][j] = f2_result[j];
    }

    for (int j = 0; j < 3; ++j) {
        if (p3[1][j]->ii != expected_values[j]) {
            std::cerr << "STOP 3" << std::endl;
            return 3;
        }
    }

    return 0;
}