#include <iostream>
#include <array>

void manipulateArray(std::array<int, 4>& a) {
    // Perform some manipulation on the array
    for (size_t i = 1; i < a.size(); i += 2) {
        a[i] = a[i] + 1;
    }
}

int main() {
    std::array<int, 4> a = {1, 2, 3, 4};
    manipulateArray(a);
    
    // Test the array
    bool test_passed = (a == std::array<int, 4>{1, 3, 3, 5});
    if (test_passed) {
        std::cout << "C++ Test Passed" << std::endl;
    } else {
        std::cout << "C++ Test Failed" << std::endl;
    }
    
    return 0;
}