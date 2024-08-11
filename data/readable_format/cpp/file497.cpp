#include <iostream>

class t {
public:
    // Example member functions simulating Fortran procedures
    static void s1(int y) {
        std::cout << "s1 called with y = " << y << std::endl;
    }

    static void s2(const t& y, float& x) {
        std::cout << "s2 called" << std::endl;
        x = 0.0f;  // Example assignment
    }
};

void test_m1() {
    t x;
    float a;
    int y = 5;

    // Test s1
    t::s1(y);

    // Test s2
    t::s2(x, a);
}

int main() {
    test_m1();
    return 0;
}