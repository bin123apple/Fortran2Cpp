#include <iostream>

int main() {
    int nums[2]; // In C++, array indices start at 0, unlike Fortran which starts at 1.
    int &n1 = nums[0]; // Reference to the first element of nums, equivalent to nums(1) in Fortran.
    int &n2 = nums[1]; // Reference to the second element of nums, equivalent to nums(2) in Fortran.

    n1 = 12;
    n2 = 34;

    // Printing the nums array.
    std::cout << nums[0] << " " << nums[1] << std::endl;

    // Changing values via the nums array.
    nums[0] = 56;
    nums[1] = 78;

    // Printing the values referred to by n1 and n2, which are affected by the changes above.
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;

    return 0;
}