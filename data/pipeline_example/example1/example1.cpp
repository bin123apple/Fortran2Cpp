#include <cassert>
#include <cmath>
#include <cstdio>
#include <limits>

namespace kinds {
    typedef double dp; // Fortran double precision
    typedef float sp;  // Fortran single precision
}

void test_kinds() {
    kinds::dp var_dp = 1.0;
    kinds::sp var_sp = 1.0f;

    // Test cases to check the precision
    assert(std::abs(var_dp - 1.0) < std::numeric_limits<kinds::dp>::epsilon());
    assert(std::abs(var_sp - 1.0f) < std::numeric_limits<kinds::sp>::epsilon());

    // Print test results
    printf("Double Precision Test Passed\n");
    printf("Single Precision Test Passed\n");
}

int main() {
    test_kinds();
    return 0;
}