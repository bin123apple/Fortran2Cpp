#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element
#include <iterator>  // For std::distance
#include <cassert>   // For assert()

// Declaration of the iminloc template function
template <typename T>
size_t iminloc(const std::vector<T>& array) {
    auto minElementIter = std::min_element(array.begin(), array.end());
    // std::distance calculates the number of elements between two iterators.
    // Adding 1 to make the index 1-based, matching the Fortran convention.
    return std::distance(array.begin(), minElementIter) + 1;
}

int main() {
    // Test for integer array
    std::vector<int> intArray = {5, 3, 2, 4, 1};
    assert(iminloc(intArray) == 5); // Min element at index 5 (1-based indexing)
    std::cout << "Integer array test passed." << std::endl;

    // Test for single-precision float array
    std::vector<float> floatArray = {3.5f, 2.5f, 1.5f, 4.5f};
    assert(iminloc(floatArray) == 3); // Min element at index 3
    std::cout << "Float array test passed." << std::endl;

    // Test for double-precision float array
    std::vector<double> doubleArray = {2.4, 3.6, 1.2, 4.8};
    assert(iminloc(doubleArray) == 3); // Min element at index 3
    std::cout << "Double array test passed." << std::endl;

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}