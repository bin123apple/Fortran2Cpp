#include <iostream>
#include <functional>

int hello() {
    return 42;
}

void test(bool first) {
    static std::function<int()> x = nullptr;

    if (first) {
        if (x != nullptr) {
            std::abort();
        }
        x = hello;
    } else {
        if (x == nullptr) {
            std::abort();
        }
        int i = x();
        if (i != 42) {
            std::abort();
        }
    }
}

int main() {
    test(true);
    test(false);
    return 0;
}