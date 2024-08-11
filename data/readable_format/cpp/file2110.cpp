#include <cinttypes>
#include <iostream>
#include <vector>

extern "C" {
    void sub0(int32_t* assumed_array, std::size_t n) {
        for (std::size_t i = 0; i < n; ++i) {
            assumed_array[i]++;
        }
    }

    void sub1(int32_t* deferred_array, std::size_t n) {
        for (std::size_t i = 0; i < n; ++i) {
            deferred_array[i]++;
        }
    }
}

void test_sub0() {
    std::cout << "Testing sub0..." << std::endl;
    int32_t array[] = {1, 2, 3, 4, 5};
    sub0(array, 5);
    bool success = true;
    for (int i = 0; i < 5; ++i) {
        if (array[i] != i + 2) {
            success = false;
            break;
        }
    }
    if (success) {
        std::cout << "sub0 test passed." << std::endl;
    } else {
        std::cout << "sub0 test failed." << std::endl;
    }
}

void test_sub1() {
    std::cout << "Testing sub1..." << std::endl;
    int32_t array[] = {10, 20, 30};
    sub1(array, 3);
    bool success = true;
    for (int i = 0; i < 3; ++i) {
        if (array[i] != i * 10 + 11) { // Expecting 11, 21, 31
            success = false;
            break;
        }
    }
    if (success) {
        std::cout << "sub1 test passed." << std::endl;
    } else {
        std::cout << "sub1 test failed." << std::endl;
    }
}

int main() {
    test_sub0();
    test_sub1();
    return 0;
}