#include <iostream>
#include <array>

int main() {
    std::array<int, 2> nums1 = {11, 17};
    std::array<int, 2> nums2 = {19, 23};

    for (int i = 0; i < 2; ++i) {
        std::cout.width(3); // To mimic the Fortran output formatting '(2i3)'
        std::cout << nums1[i] + nums2[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}