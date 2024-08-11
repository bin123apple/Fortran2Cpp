#include <iostream>
#include <vector>
#include <cassert>

int main() {
    int n = 10; // Size of the vector
    std::vector<int> vec;

    // Allocate and initialize vector
    for (int i = 1; i <= n; ++i) {
        vec.push_back(i);
    }

    // Tests
    assert(vec.size() == n && "Test 1 Failed: Vector size is incorrect.");
    std::cout << "Test 1 Passed: Vector size is correct." << std::endl;

    assert(vec[0] == 1 && "Test 2 Failed: First element is not 1.");
    std::cout << "Test 2 Passed: First element is 1." << std::endl;

    return 0;
}