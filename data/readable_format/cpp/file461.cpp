#include <iostream>
#include <cstdlib> // For std::exit()

void foo() {
    static union {
        int a;
        int b;
    } shared;

    shared.a = 5;
    if (shared.b != 5) {
        std::exit(1);
    }
}

int main() {
    foo();
    return 0;
}