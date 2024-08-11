#include <cstdlib>
#include <algorithm>
#include <array>
#include <iostream>

constexpr int file_storage_size = 8;
constexpr int character_storage_size = 8;
constexpr std::array<int, 5> numeric_storage_sizes = {8, 16, 32, 64, 128};
constexpr int iostat_end = -1;
constexpr int iostat_eor = -2;

bool check_conditions() {
    if (file_storage_size != 8) return false;
    if (character_storage_size != 8) return false;
    if (!std::all_of(numeric_storage_sizes.begin(), numeric_storage_sizes.end(),
                     [](int size) { return size == 8 || size == 16 || size == 32 || size == 64 || size == 128; })) {
        return false;
    }
    if (iostat_end != -1) return false;
    if (iostat_eor != -2) return false;
    return true;
}

int main() {
    if (!check_conditions()) {
        std::cerr << "Test failed: A condition was not met.";
        return EXIT_FAILURE;
    }
    std::cout << "All checks passed successfully.";
    return EXIT_SUCCESS;
}