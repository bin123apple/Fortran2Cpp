#include <array>
#include <iostream>
#include <cassert>

class rrsw_kg20 {
public:
    std::array<float, 5> a = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::array<float, 5> b = {5.0f, 4.0f, 3.0f, 2.0f, 1.0f};

    void modify_arrays() {
        a[0] = 10.0f; // Modify first element of a
        b[0] = 20.0f; // Modify first element of b
    }
};

int main() {
    rrsw_kg20 instance;
    instance.modify_arrays();

    // Test 1: Check if a[0] was modified
    assert(instance.a[0] == 10.0f);
    std::cout << "Test 1 Passed: a[0] was modified correctly." << std::endl;

    // Test 2: Check if b[0] was modified
    assert(instance.b[0] == 20.0f);
    std::cout << "Test 2 Passed: b[0] was modified correctly." << std::endl;

    return 0;
}