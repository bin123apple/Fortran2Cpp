#include <iostream>
#include <cassert>
#include <functional>

// Function declaration of extfunc before its use
float extfunc(float x);

namespace mod1 {
    float eval(std::function<float(float)> func, float x1) {
        return func(x1);
    }
}

namespace mod2 {
    void foo(float &x0) {
        float x1 = 42;
        // Now extfunc is already declared before this usage
        x0 = mod1::eval(extfunc, x1);
    }
}

// Function definition of extfunc
float extfunc(float x) {
    return x;
}

void test_foo() {
    float x0 = 0;
    mod2::foo(x0);
    assert(x0 == 42.0f);
    std::cout << "Test passed: x0 = " << x0 << std::endl;
}

int main() {
    test_foo();
    return 0;
}