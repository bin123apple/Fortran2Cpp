#include <iostream>
#include <vector>
#include <cstdlib> // For std::abort()

// Equivalent to Fortran's type t_1
struct t_1 {
    float coeff;
    t_1(float c = 99.0f) : coeff(c) {} // Constructor with default value matching Fortran's initialization
};

// Equivalent to Fortran's type t_2
struct t_2 {
    std::vector<t_1> mons;
    t_2(int size = 1, t_1 mon = t_1()) : mons(size, mon) {} // Constructor with default size and value
};

// Equivalent to Fortran's function a_fun
std::vector<t_2> a_fun(int r) {
    std::vector<t_2> p(r + 1, t_2()); // Create a vector of t_2 of size r+1
    return p;
}

// Test function
void test_a_fun() {
    // Test a_fun with input 0
    auto result = a_fun(0);
    if (!(result.size() == 1 && result[0].mons[0].coeff == 99.0f)) {
        std::cerr << "Test failed for a_fun with input 0" << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed for a_fun with input 0" << std::endl;
    }

    // Test a_fun with input 1
    result = a_fun(1);
    bool all_99 = true;
    for (const auto& t2_instance : result) {
        for (const auto& t1_instance : t2_instance.mons) {
            if (t1_instance.coeff != 99.0f) {
                all_99 = false;
                break;
            }
        }
        if (!all_99) break;
    }

    if (!all_99) {
        std::cerr << "Test failed for a_fun with input 1" << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed for a_fun with input 1" << std::endl;
    }
}

int main() {
    test_a_fun();
    return 0;
}