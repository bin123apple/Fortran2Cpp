#include <iostream>
#include <cstdlib>

// Declaration of f_static_a and f to make them accessible
int f_static_a = 0;

int f(int x) {
    f_static_a += x;
    return f_static_a;
}

void assert_test(const char* s, int i1, int i2) {
    if (i1 != i2) {
        std::cout << s << ": expected " << i2 << " but was " << i1 << std::endl;
        std::exit(1);
    }
}

void test_f() {
    // Reset global state
    f_static_a = 0;
    assert_test("f()", f(3), 3);
    assert_test("f()", f(4), 7);
    assert_test("f()", f(2), 9);
}

void test_g_and_h() {
    // Placeholder: Implementations for g and h tests would go here
    // Note: Testing g and h would likely require adjustments to allow for proper state management or isolation for tests
}

int main() {
    test_f();
    test_g_and_h();

    std::cout << "All tests passed." << std::endl;
    return 0;
}