#include <iostream>
#include <string>
#include <cassert>
#include <limits>

// Namespace to mimic the Fortran module functionality
namespace dropdep_var {
    // Constants
    const int pi = 5;
    const int dp = std::numeric_limits<double>::digits10;

    // Variables
    double r;
    std::string chr1;
}

// Simple function to test the variables
void test_dropdep_var() {
    using namespace dropdep_var;

    // Assign values to the variables
    r = 3.14;
    chr1 = "abcde";

    // Output the variables to verify the assignment
    std::cout << "r = " << r << std::endl;
    std::cout << "chr1 = " << chr1 << std::endl;

    // Check the length of chr1
    assert(chr1.length() == pi && "Test Failed: Length of chr1 is not equal to pi");
    std::cout << "Test Passed: Length of chr1 is equal to pi" << std::endl;
}

// Main function to run the tests
int main() {
    test_dropdep_var();
    return 0;
}