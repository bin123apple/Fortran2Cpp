#include <iostream>

struct Sub {
    int i;
};

struct T {
    Sub sub;
};

union TU {
    int i;
    float r;
};

void sub0(T& u) {
    u.sub.i = 0;
}

void sub1() {
    T u;
    sub0(u);
    // If you need to see the result, add a print statement:
    // std::cout << "u.sub.i = " << u.sub.i << std::endl;
}

void sub2(TU& u) {
    u.r = 1.0f;
}

int main() {
    T u;
    TU u2;

    sub0(u);
    std::cout << "After sub0: u.sub.i = " << u.sub.i << std::endl;

    sub1();
    // Note: sub1 creates a local T u and calls sub0 on it, but does not affect main's u

    sub2(u2);
    std::cout << "After sub2: u2.r = " << u2.r << std::endl;

    return 0;
}