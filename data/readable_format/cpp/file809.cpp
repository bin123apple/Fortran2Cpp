#include <vector>

void permuteElementsLogical1D(std::vector<bool>& arrayToPermute, std::vector<bool>& tempArray, const std::vector<int>& perm, int nSpec) {
    // Ensure tempArray has the same size as arrayToPermute
    tempArray.resize(arrayToPermute.size());

    // Perform the permutation
    for (int i = 0; i < nSpec; ++i) {
        // Note: Subtract 1 from perm[i] to convert from Fortran 1-indexing to C++ 0-indexing
        tempArray[i] = arrayToPermute[perm[i] - 1];
    }

    // Copy the permuted elements back to arrayToPermute
    arrayToPermute = tempArray;
}

// Example usage
#include <iostream>

int main() {
    std::vector<bool> arrayToPermute = {true, false, true, false};
    std::vector<bool> tempArray; // Will be resized within the function
    std::vector<int> perm = {4, 3, 2, 1}; // Example permutation array

    permuteElementsLogical1D(arrayToPermute, tempArray, perm, arrayToPermute.size());

    for (bool val : arrayToPermute) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}