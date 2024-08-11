#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

void testArray() {
    std::vector<int> arr(6);
    std::iota(arr.begin(), arr.end(), 1); // Fill with values 1 to 6

    // Check values
    for (size_t i = 0; i < arr.size(); ++i) {
        assert(arr[i] == static_cast<int>(i + 1)); // +1 for 1-based indexing
    }

    std::cout << "C++ test passed." << std::endl;
}

int main() {
    testArray();
    return 0;
}