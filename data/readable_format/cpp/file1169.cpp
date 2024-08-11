#include <iostream>
#include <vector>
#include <algorithm> // For std::fill

// Function to test if all elements in a vector are equal to a given value
template<typename T>
bool test_all_elements_equal(const std::vector<T>& vec, T value) {
    return std::all_of(vec.begin(), vec.end(), [value](T elem){ return elem == value; });
}

// Function to run all tests
void run_tests() {
    const int N = 64;
    std::vector<float> a(N), b(N);

    std::fill(a.begin(), a.end(), 3.0f);
    std::fill(b.begin(), b.end(), 0.0f);

    // Test if all elements in a are 3.0
    if (test_all_elements_equal(a, 3.0f)) {
        std::cout << "Test Passed: All elements in array a are 3.0" << std::endl;
    } else {
        std::cout << "Test Failed: Not all elements in array a are 3.0" << std::endl;
    }

    // Test if all elements in b are 0.0
    if (test_all_elements_equal(b, 0.0f)) {
        std::cout << "Test Passed: All elements in array b are 0.0" << std::endl;
    } else {
        std::cout << "Test Failed: Not all elements in array b are 0.0" << std::endl;
    }
}

int main() {
    run_tests();
    return 0;
}