#include <iostream>

// Namespace to encapsulate our functionality, mimicking the modular approach
namespace ppm_module_fmm_finalize {

// Function to add two numbers
void add_numbers(int a, int b, int& result) {
    result = a + b;
}

} // namespace ppm_module_fmm_finalize

// Simple function to test add_numbers
void test_add_numbers() {
    int result;
    ppm_module_fmm_finalize::add_numbers(3, 4, result);

    if (result == 7) {
        std::cout << "Test passed: 3 + 4 = " << result << std::endl;
    } else {
        std::cerr << "Test failed: 3 + 4 did not equal " << result << std::endl;
    }
}

int main() {
    // Run our test
    test_add_numbers();

    return 0;
}