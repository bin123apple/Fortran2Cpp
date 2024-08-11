#include <iostream>
#include <cassert>

namespace cdat {
    double al;
    double beta;
}

// Define the init_pars function that initializes al and beta within the cdat namespace
void init_pars() {
    cdat::al = 16.0;
    cdat::beta = 128.0;
}

// Unit test function to verify the initialization is correct
void test_init_pars() {
    init_pars(); // Call the function to initialize parameters

    // Assert to check if the values are as expected
    assert(cdat::al == 16.0 && "al should be initialized to 16.0");
    assert(cdat::beta == 128.0 && "beta should be initialized to 128.0");

    std::cout << "All tests passed." << std::endl; // Confirmation message if assertions pass
}

// Main function to run the test
int main() {
    test_init_pars(); // Execute the unit test
    return 0;
}