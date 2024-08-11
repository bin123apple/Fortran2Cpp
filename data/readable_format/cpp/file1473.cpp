#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>

// Define maxloc function for a 1D vector
int maxloc(const std::vector<int>& v) {
    if (v.empty()) return -1; // Mimic Fortran behavior for empty arrays
    auto it = std::max_element(v.begin(), v.end());
    return std::distance(v.begin(), it);
}

// Define minloc function for a 2D vector
std::pair<int, int> minloc(const std::vector<std::vector<int>>& v) {
    std::pair<int, int> loc = {-1, -1};
    if (v.empty() || v[0].empty()) return loc; // Handle empty 2D vector
    int minVal = std::numeric_limits<int>::max();
    
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            if (v[i][j] < minVal) {
                minVal = v[i][j];
                loc = {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return loc;
}

int main() {
    // Test 1: Empty 1D vector
    std::vector<int> d(0);
    assert(maxloc(d) == -1);
    std::cout << "Test 1 Passed" << std::endl;

    // Test 2: Empty 2D vector
    std::vector<std::vector<int>> a(1, std::vector<int>(0));
    auto b = minloc(a);
    assert(b.first == -1 && b.second == -1);
    std::cout << "Test 2 Passed" << std::endl;

    // Test 3: Non-empty 1D vector
    d = {3, 1, 2}; // Reuse d for a new test
    assert(maxloc(d) == 0); // Index of max value (3) is 0
    std::cout << "Test 3 Passed" << std::endl;

    // Test 4: Non-empty 2D vector
    a = {{4, 1}, {3, 2}}; // 2x2 vector
    b = minloc(a);
    assert(b.first == 0 && b.second == 1); // Location of min value (1) is (0,1)
    std::cout << "Test 4 Passed" << std::endl;

    return 0;
}