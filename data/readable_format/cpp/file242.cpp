#include <iostream>
#include <vector>
#include <cstdlib> // For std::abort
#include <algorithm> // For std::equal

// A template function to mimic Fortran's merge for scalar values
template<typename T>
T merge(const T& t, const T& f, bool condition) {
    return condition ? t : f;
}

// A template function to mimic Fortran's merge for arrays (vectors in C++)
template<typename T>
std::vector<T> merge(const std::vector<T>& t, const std::vector<T>& f, const std::vector<bool>& condition) {
    std::vector<T> result(t.size());
    for (size_t i = 0; i < t.size(); ++i) {
        result[i] = condition[i] ? t[i] : f[i];
    }
    return result;
}

void assertEqual(int expected, int actual, const std::string& message) {
    if (expected != actual) {
        std::cerr << message << " -- Test failed. Expected " << expected << " but got " << actual << std::endl;
        std::abort();
    } else {
        std::cout << message << " -- Test passed." << std::endl;
    }
}

void assertVectorEqual(const std::vector<int>& expected, const std::vector<int>& actual, const std::string& message) {
    if (expected.size() != actual.size() || !std::equal(expected.begin(), expected.end(), actual.begin())) {
        std::cerr << message << " -- Test failed." << std::endl;
        std::abort();
    } else {
        std::cout << message << " -- Test passed." << std::endl;
    }
}

int main() {
    // Test 1: merge with i > 3
    assertEqual(-1, merge(-1, 1, 5 > 3), "Test 1");
    
    // Test 2: merge with i >= 3
    assertEqual(1, merge(-1, 1, 1 >= 3), "Test 2");

    // Test 3: merge arrays based on a condition
    std::vector<int> a = {-1, 2, 3};
    std::vector<bool> condition = {false, true, true};
    std::vector<int> expected = {0, 2, 3};
    assertVectorEqual(expected, merge(a, std::vector<int>(3, 0), condition), "Test 3");

    return 0;
}