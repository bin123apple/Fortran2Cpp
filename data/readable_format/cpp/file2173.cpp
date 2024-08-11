#include <iostream>
#include <array>

// Declaration of foo
void foo(int n1, std::array<int64_t, 3> n2, int n3, int64_t& n4) {
    n4 = (n1 + n2[2]) / 2 + n3;
}

// Unit test for foo
void test_foo() {
    int n1 = 2, n3 = 1;
    std::array<int64_t, 3> n2 = {1, 2, 3};
    int64_t n4;

    foo(n1, n2, n3, n4);

    if (n4 != 3) {
        std::cerr << "Test failed: Expected 3, got " << n4 << std::endl;
    } else {
        std::cout << "Test passed: n4 = " << n4 << std::endl;
    }
}

int main() {
    test_foo();
    return 0;
}