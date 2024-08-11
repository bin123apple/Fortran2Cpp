#include <iostream>
#include <array>
#include <iomanip>
#include <string>

int main() {
    // Initialize the 2x2 integer array
    std::array<std::array<int, 2>, 2> nums = {{{12, 34}, {56, 78}}};
    // Initialize the 2x2 string array for character handling
    std::array<std::array<std::string, 2>, 2> s2s = {{{"Xy", "Za"}, {"cD", "eF"}}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // Output formatting similar to Fortran's
            std::cout << std::setw(2) << nums[i][j] << " " << s2s[i][j] << std::endl;
        }
    }

    return 0;
}