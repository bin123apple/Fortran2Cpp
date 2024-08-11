// Filename: alloc_test.cpp
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    std::vector<int> a;

    try {
        // Simulate allocation with size 4
        a.resize(4);
    } catch (const std::bad_alloc&) {
        std::cout << "C++ Stdout: Allocation of a failed" << std::endl;
        return 1;
    }

    // Simulate "reallocation" to size 3. In C++, resize will not throw if reducing size.
    try {
        a.resize(3);
    } catch (const std::bad_alloc&) {
        std::cout << "C++ Stdout: Reallocation of a failed" << std::endl;
        return 1;
    }

    // Check the size of vector a
    if (a.size() != 3) {
        std::cout << "C++ Stdout: Unit test failed" << std::endl;
        return 1;
    }

    std::cout << "C++ Stdout: Unit test passed" << std::endl;
    return 0;
}