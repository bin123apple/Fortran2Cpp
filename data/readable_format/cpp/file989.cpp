#include <iostream>
#include <cstdint> // For int64_t
#include <cassert>

// Using namespace to simulate Fortran module
namespace template_module {

// Equivalent to Fortran's templ function
int64_t templ(int64_t n) {
    return n * n;
}

// Equivalent to Fortran's test subroutine
void test(int64_t& n) {
    n = n + 1;
    std::cout << "hello module" << std::endl;
}

} // End of namespace template_module

int main() {
    // Test templ function
    int64_t number = 5;
    int64_t result = template_module::templ(number);
    assert(result == 25);
    std::cout << "Test templ passed: Expected 25, Got " << result << std::endl;

    // Test test subroutine
    number = 10;
    template_module::test(number);
    assert(number == 11);
    std::cout << "Test test passed: Expected 11, Got " << number << std::endl;

    std::cout << "All tests passed." << std::endl;

    return 0;
}