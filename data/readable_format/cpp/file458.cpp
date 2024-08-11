#include <iostream>
#include <vector>

std::vector<int> calculate_values() {
    const int size = 4;
    std::vector<int> a(size);
    bool mask1[size] = {true, true, false, false};
    bool mask2[size] = {true, false, true, false};

    for (int i = 0; i < size; ++i) {
        if (mask1[i]) {
            if (mask2[i]) {
                a[i] = 1;
            } else {
                a[i] = 2;
            }
        } else {
            if (mask2[i]) {
                a[i] = 3;
            } else {
                a[i] = 4;
            }
        }
    }

    return a;
}

void test_calculate_values(const std::vector<int>& expected) {
    auto result = calculate_values();
    bool passed = true;
    for (size_t i = 0; i < expected.size(); ++i) {
        if (result[i] != expected[i]) {
            std::cerr << "Test failed at index " << i << ". Expected: " << expected[i] << ", Got: " << result[i] << std::endl;
            passed = false;
        }
    }
    if (passed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    // Test the function with an expected output
    std::vector<int> expected = {1, 2, 3, 4};
    test_calculate_values(expected);

    return 0;
}