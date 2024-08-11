#include <iostream>
#include <vector>
#include <cassert>

void foo(std::vector<std::vector<double>>& arr) {
    // Adjusting the indices to 0-based for C++
    arr[2][3] = 24;
}

void bar(std::vector<std::vector<double>>& arr) {
    // Call `foo` directly with the whole array
    foo(arr);
    
    // The original intention was to demonstrate passing a modified array,
    // but C++ vectors are passed by reference, so modifications in `foo` are already reflected in `arr`.
    // Here, we call `foo` again just to match the original structure,
    // but in a real scenario, this might be unnecessary or different based on the actual logic needed.
    foo(arr);
}

int main() {
    std::vector<std::vector<double>> arr(5, std::vector<double>(8, 0.0));

    bar(arr);

    // Assert to verify the correctness of the operation
    assert(arr[2][3] == 24);

    std::cout << "Test passed." << std::endl;

    return 0;
}