// main.cpp
#include <iostream>
#include <iomanip>

void foo(float a) {
    std::cout << std::fixed << std::setprecision(8) << a << std::endl;  // Match Fortran output format.
}

class X {
public:
    static void a() {
        foo(1.0f);  // Call foo with a float literal.
    }
};

int main() {
    X::a();  // This should print "1.00000000" or a close representation.

    // Direct test
    foo(1.0f);  // Testing foo directly with the same value.
    std::cout << "Test passed if 1.00000000 printed twice." << std::endl;
    return 0;
}