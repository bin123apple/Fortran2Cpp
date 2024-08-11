#include <iostream>
#include <array>
#include <string>

void printReversed(const std::array<std::string, 6>& arr) {
    for (int i = arr.size() - 1; i >= 0; --i) {
        std::cout << arr[i] << std::endl; // Use endl to match Fortran's line break
    }
}

int main() {
    std::array<std::string, 6> d = { "1", "hElLo", "W", "orld", " !", " " };

    printReversed(d);

    return 0;
}