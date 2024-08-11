#include <iostream>
#include <cmath>
#include <string>

// Correcting the variable name to match the Fortran version
double XYTRAN_TRCOEFFS = 0.0;
double XYFIT_TRCOEFFS = 5.0;

void test_assignment() {
    // Use the correct variable name without the leading underscore
    XYTRAN_TRCOEFFS = XYFIT_TRCOEFFS;
}

// A very basic testing function
void assert_equal(double expected, double actual, const std::string& test_name) {
    if (std::fabs(expected - actual) < 1e-6) {
        std::cout << "PASSED: " << test_name << std::endl;
    } else {
        std::cout << "FAILED: " << test_name << " - Expected: " << expected << ", Actual: " << actual << std::endl;
    }
}

int main() {
    // Run the assignment function
    test_assignment();

    // Test to ensure the assignment worked as expected
    assert_equal(XYFIT_TRCOEFFS, XYTRAN_TRCOEFFS, "Test XYTRAN_TRCOEFFS assignment");

    return 0;
}