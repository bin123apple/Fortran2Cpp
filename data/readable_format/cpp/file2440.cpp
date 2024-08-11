#include <iostream>
#include <stdexcept>
#include <cassert>

namespace mathlib {

    int add(int lhs, int rhs) {
        return lhs + rhs;
    }

    int sub(int lhs, int rhs) {
        return lhs - rhs;
    }

    int mul(int lhs, int rhs) {
        return lhs * rhs;
    }

    int divide(int lhs, int rhs) {
        if (rhs == 0) {
            throw std::invalid_argument("Division by zero is undefined.");
        }
        return lhs / rhs;
    }

    int mod(int lhs, int rhs) {
        if (rhs == 0) {
            throw std::invalid_argument("Modulo by zero is undefined.");
        }
        return lhs % rhs;
    }

} // namespace mathlib

void runTests() {
    using namespace mathlib;

    assert(add(10, 3) == 13);
    assert(sub(10, 3) == 7);
    assert(mul(10, 3) == 30);
    assert(divide(10, 3) == 3);
    assert(mod(10, 3) == 1);

    std::cout << "All tests passed." << std::endl;
}

int main() {
    runTests();

    return 0;
}