#include <iostream>
#include <cstdlib>

namespace lib {
    int var_i = 1;

    void lib_func() {
        if (var_i != 1) std::abort();
        var_i = 2;
        // var_i = var_i; // This line is redundant and has been commented out.
    }
}

namespace libmany {
    int var_j = 3;
    int var_k = 4;
}

// Basic testing mechanism without external libraries
void test_var_i_initial_value() {
    if (lib::var_i != 1) {
        std::cerr << "Test Failed: Initial value of var_i is incorrect."
                  << std::endl;
        std::exit(1);
    } else {
        std::cout << "Test Passed: Initial value of var_i is correct."
                  << std::endl;
    }
}

void test_var_i_after_lib_func() {
    lib::lib_func();
    if (lib::var_i != 2) {
        std::cerr << "Test Failed: Value of var_i after calling lib_func is incorrect."
                  << std::endl;
        std::exit(1);
    } else {
        std::cout << "Test Passed: Value of var_i after calling lib_func is correct."
                  << std::endl;
    }
}

int main() {
    // Run tests
    test_var_i_initial_value();
    test_var_i_after_lib_func();

    // Example usage
    std::cout << "var_i: " << lib::var_i << std::endl;
    std::cout << "var_j: " << libmany::var_j << std::endl;
    std::cout << "var_k: " << libmany::var_k << std::endl;

    return 0;
}