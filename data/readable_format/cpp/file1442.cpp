#include <iostream>
#include <cstdlib>
#include <cassert>

void transform_and_test() {
    int p[4] = {2, 4, 1, 3};
    int temp[4]; // Temporary array for assignment

    // First transformation
    for(int i = 0; i < 4; ++i) {
        temp[p[i] - 1] = i + 1;
    }
    for(int i = 0; i < 4; ++i) {
        p[i] = temp[i];
    }

    // Test after first transformation
    int expected_first_pass[4] = {3, 1, 4, 2};
    for(int i = 0; i < 4; ++i) {
        assert(p[i] == expected_first_pass[i]);
    }

    int p2[4] = {2, 4, 1, 3}; // Reset p for the second transformation

    // Second transformation
    for(int i = 0; i < 4; ++i) {
        temp[4 - p2[i]] = p2[4 - i - 1];
    }
    for(int i = 0; i < 4; ++i) {
        p2[i] = temp[i];
    }

    // Test after second transformation
    int expected_second_pass[4] = {1, 2, 3, 4};
    for(int i = 0; i < 4; ++i) {
        assert(p2[i] == expected_second_pass[i]);
    }

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    transform_and_test();
    return 0;
}