#include <iostream>
#include <cassert>

union s1 {
    float a;
    // Constructor to initialize 'a'
    s1() : a(2.0f) {}
};

void test_myStruct(const s1& s) {
    const float expected_value = 2.0f;
    assert(s.a == expected_value && "Test failed");
    std::cout << "Test passed, a = " << s.a << std::endl;
}

int main() {
    s1 myStruct;
    test_myStruct(myStruct);
    return 0;
}