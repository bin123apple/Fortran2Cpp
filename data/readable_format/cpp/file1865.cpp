#include <iostream>
#include <functional>
#include <cstdlib>

class m {
public:
    static bool was_foo;

    static void foo(int a, int b) {
        if ((a != 3) || (b != 4)) std::abort();
        was_foo = true;
    }

    static void bar(int a) {
        if (a != 5) std::abort();
        was_foo = false;
    }

    static void indirecta(std::function<void(int, int)> p) {
        p(3, 4);
    }

    static void indirectb(std::function<void(int)> p) {
        p(5);
    }

    static void test1() {
        indirecta(foo);
        indirectb(bar);
    }

    static void test2() {
        foo(3, 4);
        bar(5);
    }
};

bool m::was_foo = false;

int main() {
    m::test1();
    m::test2();
    std::cout << "C++: All tests passed successfully." << std::endl;
    return 0;
}