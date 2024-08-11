// file: test.cpp
#include <iostream>

void test_i(int i) {
    if (i == 2000) {
        std::cout << "Test passed: i = " << i << std::endl;
    } else {
        std::cout << "Test failed: i = " << i << std::endl;
    }
}

int main() {
    int i = 2000;
    test_i(i);
    return 0;
}