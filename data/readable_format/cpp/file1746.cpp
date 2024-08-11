#include <iostream>
#include <cassert>

namespace m {

    struct t1 {
        int a = 42;
        int b;

        t1() = default;
        t1(int aVal, int bVal) : a(aVal), b(bVal) {}
    };

    struct t2 {
        int a;
        int b;

        t2() : a(0), b(0) {}
        t2(int aVal, int bVal) : a(aVal), b(bVal) {}
    };

    void sub1(t1& x) {
        // t1's default initialization sets a = 42, so nothing is needed here.
    }

    void sub2(t2& x) {
        x.a = 42;
    }

    void sub3(t2& x) {
        // This function intentionally left blank.
    }

} // End of namespace m

int main() {
    // Test for sub1
    {
        m::t1 x1;
        m::sub1(x1);
        assert(x1.a == 42);
        std::cout << "Test sub1 passed: a = " << x1.a << std::endl;
    }

    // Test for sub2
    {
        m::t2 x2;
        m::sub2(x2);
        assert(x2.a == 42);
        std::cout << "Test sub2 passed: a = " << x2.a << std::endl;
    }

    // Test for sub3
    {
        m::t2 x3;
        // Assign some values before calling sub3
        x3.a = 1; x3.b = 2;
        m::sub3(x3);
        // sub3 should not alter the values
        assert(x3.a == 1 && x3.b == 2);
        std::cout << "Test sub3 passed: a = " << x3.a << ", b = " << x3.b << std::endl;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}