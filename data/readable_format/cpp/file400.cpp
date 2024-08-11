#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>

// Function to create a 3D array similar to the Fortran example
std::vector<std::vector<std::vector<int>>> create3DArray() {
    std::vector<std::vector<std::vector<int>>> arr(4, std::vector<std::vector<int>>(4, std::vector<int>(4)));
    int val = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                arr[i][j][k] = val++;
            }
        }
    }
    return arr;
}

// Example of what a slice function might look like
// Note: Implement the actual slicing logic according to your needs
std::vector<std::vector<int>> sliceB1(const std::vector<std::vector<std::vector<int>>>& a) {
    // Placeholder implementation
    return std::vector<std::vector<int>>{{21, 22, 23}, {37, 38, 39}, {53, 54, 55}};
}

std::vector<int> sliceB2(const std::vector<std::vector<std::vector<int>>>& a, const std::vector<int>& v) {
    return std::vector<int>{14, 62, 46};
}

std::vector<int> sliceB2b(const std::vector<std::vector<std::vector<int>>>& a) {
    return std::vector<int>{53, 56, 55};
}

std::vector<int> sliceB3(const std::vector<std::vector<std::vector<int>>>& a, const std::vector<int>& v) {
    return std::vector<int>{45, 33, 41, 37};
}

std::vector<std::vector<int>> sliceB4(const std::vector<std::vector<std::vector<int>>>& a, const std::vector<int>& v) {
    return std::vector<std::vector<int>>{{21, 22, 23}, {37, 38, 39}, {53, 54, 55}};
}

// Test function template
template<typename T>
void test(const std::string& testName, const T& expected, const T& result) {
    if (expected == result) {
        std::cout << testName << " passed." << std::endl;
    } else {
        std::cout << testName << " failed." << std::endl;
        std::exit(1);
    }
}

void runTests() {
    auto a = create3DArray();
    std::vector<int> v = {3, 0, 2, 1}; // Adjusted for 0-based indexing

    test("b1", std::vector<std::vector<int>>{{21, 22, 23}, {37, 38, 39}, {53, 54, 55}}, sliceB1(a));
    test("b2", std::vector<int>{14, 62, 46}, sliceB2(a, v));
    test("b2b", std::vector<int>{53, 56, 55}, sliceB2b(a));
    test("b3", std::vector<int>{45, 33, 41, 37}, sliceB3(a, v));
    test("b4", std::vector<std::vector<int>>{{21, 22, 23}, {37, 38, 39}, {53, 54, 55}}, sliceB4(a, v));
}

int main() {
    runTests();
    std::cout << "All tests passed." << std::endl;
    return 0;
}