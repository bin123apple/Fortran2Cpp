#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>

// Elemental function
int e_fn(int p, int q) {
    return p - q;
}

// Helper function to check if any element in the array meets a condition
template<typename T, size_t R, size_t C>
bool any_of(const std::array<std::array<T, C>, R>& arr, T val) {
    for (const auto& row : arr) {
        if (std::any_of(row.begin(), row.end(), [val](T element){ return element != val; })) {
            return true;
        }
    }
    return false;
}

// Helper function to apply e_fn element-wise to two arrays
template<size_t R, size_t C>
void apply_e_fn(std::array<std::array<int, C>, R>& arr, const std::array<std::array<int, C>, R>& other, int q) {
    for (size_t i = 0; i < R; ++i) {
        for (size_t j = 0; j < C; ++j) {
            arr[i][j] = e_fn(other[i][j], q);
        }
    }
}

void manual_tests() {
    // Test the elemental function directly
    assert(e_fn(5, 3) == 2);
    std::cout << "e_fn(5,3) = 2, passed." << std::endl;

    // More comprehensive tests can be added here
}

int main() {
    // Your main program logic here

    // After your main logic, call the manual_tests function to verify behavior
    manual_tests();

    std::cout << "All manual tests passed." << std::endl;

    return 0;
}