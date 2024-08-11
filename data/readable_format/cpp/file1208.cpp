// main.cpp
#include <iostream>
#include <cmath>
#include <cstdlib> // For std::exit

// Template function to mimic Fortran's sign function
template <typename T>
T sign(T a, T b) {
    if (b == T(0) && std::signbit(b)) // Special handling for -0.0 case
        return -std::abs(a);
    return b >= T(0) ? std::abs(a) : -std::abs(a);
}

// Function to run tests
template <typename T>
void test_sign_function(T a, T b, T expected, const std::string& test_case) {
    T result = sign(a, b);
    if ((expected == result) || (std::isnan(expected) && std::isnan(result))) {
        std::cout << "Test passed for: " << test_case << std::endl;
    } else {
        std::cerr << "Test failed for: " << test_case << ". Expected " << expected << ", got " << result << std::endl;
        std::exit(1); // Exit the program with an error code
    }
}

int main() {
    // Run test cases
    test_sign_function<int>(2, 3, 2, "Test 1");
    test_sign_function<int>(4, -5, -4, "Test 2");
    test_sign_function<int>(-6, 7, 6, "Test 3");
    test_sign_function<int>(-8, -9, -8, "Test 4");
    test_sign_function<float>(1.0f, 2.0f, 1.0f, "Test 5");
    test_sign_function<float>(1.0f, -2.0f, -1.0f, "Test 6");
    test_sign_function<float>(1.0f, 0.0f, 1.0f, "Test 7");
    test_sign_function<float>(1.0f, -0.0f, -1.0f, "Test 8"); // Adjusted for correct behavior in C++

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}